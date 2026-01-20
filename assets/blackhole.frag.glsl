#version 410 core

out vec4 out_color;

uniform vec3 camera_pos;
uniform vec2 screen_res;

struct Ray {
	vec3 pos;
	vec3 dir;
	bool alive;
};

void main()
{
	vec2 uv = (gl_FragCoord.xy / screen_res) * 2.0 - 1.0;
	uv.x *= screen_res.x / screen_res.y;

	vec3 forward = normalize(-camera_pos);
	vec3 right = normalize(cross(forward, vec3(0.0, 1.0, 0.0)));
	vec3 camera_up = cross(right, forward);

	float z = 1.0 / tan(radians(45.0) * 0.5);

	Ray ray;
	ray.dir = normalize(uv.x * right + uv.y * camera_up + z * forward);
	ray.pos = camera_pos;
	ray.alive = true;

	float step_size = 0.1;
	float epsilon = 0.001;
	float event_horizon_radius = 2.0;
	float accretion_disk_radius_inner = 6.0;
	float accretion_disk_radius_outer = 20.0;

	vec3 black_hole_pos = vec3(0.0, 0.0, 0.0);
	vec3 black_hole_up = normalize(vec3(1.0, 1.0, 0.0));

	while (ray.alive) {
		float distance_to_camera = length(ray.pos - camera_pos);

		if (distance_to_camera > 200.0) {
			out_color = vec4(0.1, 0.1, 0.1, 1.0);
			ray.alive = false;
			continue;
		}

		float distance = length(ray.pos - black_hole_pos);
		
		if (distance < event_horizon_radius) {
			out_color = vec4(0.0, 0.0, 0.0, 1.0);
			ray.alive = false;
			continue;
		}

		bool parallel_to_disk = abs(dot(ray.dir, black_hole_up)) < epsilon;
		if (!parallel_to_disk) {
			float t = -dot(ray.pos - black_hole_pos, black_hole_up) / dot(ray.dir, black_hole_up);
			bool intersection_is_behind = t < 0;
			bool intersection_in_step = t >= 0 && t <= step_size;
			if (!intersection_is_behind && intersection_in_step) {
				vec3 intersection_point = ray.pos + ray.dir * t;
				float distance_from_center = length(intersection_point - black_hole_pos);
				if (accretion_disk_radius_inner < distance_from_center && distance_from_center < accretion_disk_radius_outer) {
					ray.alive = false;
					out_color = vec4(1.0, 0.5, 0.0, 1.0);
					continue;
				}
			}
		}

		vec3 gravity_dir = normalize(black_hole_pos - ray.pos);
		float bending_strength = 3 / (distance * distance);
		ray.dir += gravity_dir * bending_strength * step_size;
		ray.dir = normalize(ray.dir);
		ray.pos += ray.dir * step_size;
	}
}
