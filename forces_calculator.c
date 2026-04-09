#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef float f32;
typedef double f64;


// Weight Force

f64 calculate_weightForce(f64 mass, f64 gravity);
f64 calculate_massFrom_weightForce(f64 force, f64 gravity);
f64 calculate_gravityFrom_weightForce(f64 force, f64 mass);

// End Weight Force

// ---------------- //

// Friction Force

f64 calculate_frictionForce(f64 friction_coeficient, f64 normal_force);
f64 calculate_frictionCoeficient_from_frictionForce(f64 frictionForce, f64 normal_force);
f64 calculate_normalForce_from_frictionForce(f64 frictionForce, f64 friction_coeficient);

// End Friction Force

// ---------------- // 

// Elastic Force

f64 calculate_springForce(f64 spring_constant, f64 spring_displacement);
f64 calculate_springConstant_from_springForce(f64 springForce, f64 spring_displacement);
f64 calculate_springDisplacement_from_springForce(f64 springForce, f64 spring_constant);

// End Elastic Force

// ---------------- //

int read_int_choice() {
	char buf[32];
	int val = 0;
	if (fgets(buf, sizeof(buf), stdin)) {
		sscanf(buf, "%d", &val);
	}
	return val;
}

int main() {

	char get_yes_no[2] = "";
	char yes_no;
	int choice = 0;

	do {
		printf("Hello and welcome to this amazing forces calculator! What do you want to calculate here?\n1 - Weight Force\n2 - Friction Force\n3 - Elastic Force\nChoice: ");
		choice = read_int_choice();

		switch (choice) {
			case 1:
				char get_weightForce[20];
				char get_mass[20];
				char get_gravity[20];
				int choice_weightForce = 0;
				f64 weightForce = 0;
				f64 mass = 0;
				f64 gravity = 0;
				printf("Firsts firsts, tell me what do you already have:\n1 - I have both mass and gravity, but no force yet\n2 - I have both force and gravity, but no mass\n3 - I have both force and mass, but no gravity.\nAnswer: ");
				choice_weightForce = read_int_choice();

				switch (choice_weightForce) {
					case 1:
						printf("Tell me the mass (kg): ");
						fgets(get_mass, sizeof(get_mass), stdin);
						sscanf(get_mass, "%lf", &mass);
				
						printf("Tell me the gravity (m/s^2): ");
						fgets(get_gravity, sizeof(get_gravity), stdin);
						sscanf(get_gravity, "%lf", &gravity);

						weightForce = calculate_weightForce(mass, gravity);

						printf("Weight Force = %.2lfN\n", weightForce);
						break;
					case 2:
						printf("Tell me the force (N): ");
						fgets(get_weightForce, sizeof(get_weightForce), stdin);
						sscanf(get_weightForce, "%lf", &weightForce);

						printf("Tell me the gravity (m/s^2): ");
						fgets(get_gravity, sizeof(get_gravity), stdin);
						sscanf(get_gravity, "%lf", &gravity);

						gravity = calculate_massFrom_weightForce(weightForce, gravity);

						printf("Mass = %.2lfkg\n", gravity);
						break;
					case 3:
						printf("Tell me the force (N): ");
						fgets(get_weightForce, sizeof(get_weightForce), stdin);
						sscanf(get_weightForce, "%lf", &weightForce);

						printf("Tell me the mass (kg): ");
						fgets(get_mass, sizeof(get_mass), stdin);
						sscanf(get_mass, "%lf", &mass);

						gravity = calculate_gravityFrom_weightForce(weightForce, mass);

						printf("Gravity = %.2lfm/s^2\n", gravity);
						break;
					}
				strcpy(get_weightForce, "");
				strcpy(get_mass, "");
				strcpy(get_gravity, "");
				break;
		
			case 2:
				char get_frictionForce[20];
				char get_frictionConstant[20];
				char get_normalForce[20];
				int choice_frictionForce = 0;
				f64 frictionForce = 0;
				f64 frictionConstant = 0;
				f64 normalForce = 0;

				printf("Firsts firsts, tell me what do you already have:\n1 - I have both friction constant and normal force, but no friction force yet\n2 - I have both friction force and friction constant, but no normal force.\n3 - I have both friction force and normal force, but no friction constant.\nAnswer: ");
				choice_frictionForce = read_int_choice();

				switch (choice_frictionForce) {
					case 1:
						printf("Tell me the friction constant (N/m): ");
						fgets(get_frictionConstant, sizeof(get_frictionConstant), stdin);
						sscanf(get_frictionConstant, "%lf", &frictionConstant);

						printf("Tell me the normal force (N): ");
						fgets(get_normalForce, sizeof(get_normalForce), stdin);
						sscanf(get_normalForce, "%lf", &normalForce);

						frictionForce = calculate_frictionForce(frictionConstant, normalForce);

						printf("Friction Force = %.2lfN\n", frictionForce);
						break;
					case 2:
						printf("Tell me the friction force (N): ");
						fgets(get_frictionForce, sizeof(get_frictionForce), stdin);
						sscanf(get_frictionForce, "%lf", &frictionForce);

						printf("Tell me the friction constant (N/m): ");
						fgets(get_frictionConstant, sizeof(get_frictionConstant), stdin);
						sscanf(get_frictionConstant, "%lf", &frictionConstant);

						normalForce = calculate_normalForce_from_frictionForce(frictionForce, frictionConstant);

						printf("Normal Force = %.2lfN\n", normalForce);
						break;
					case 3:
						printf("Tell me the friction force (N): ");
						fgets(get_frictionForce, sizeof(get_frictionForce), stdin);
						sscanf(get_frictionForce, "%lf", &frictionForce);

						printf("Tell me the normal force (N): ");
						fgets(get_normalForce, sizeof(get_normalForce), stdin);
						sscanf(get_normalForce, "%lf", &normalForce);

						frictionConstant = calculate_frictionCoeficient_from_frictionForce(frictionForce, normalForce);

						printf("Friction Constant = %.2lfn/m\n", frictionConstant);
						break;
					}
				strcpy(get_frictionForce, "");
				strcpy(get_frictionConstant, "");
				strcpy(get_normalForce, "");
				break;

			case 3:
				char get_springForce[20];
				char get_springConstant[20];
				char get_springDisplacement[20];
				int choice_springForce = 0;
				f64 springForce = 0;
				f64 springConstant = 0;
				f64 springDisplacement = 0;
				
				printf("Firsts firsts, tell me what do you already have:\n1 - I have both spring constant and spring displacement, but no spring force yet\n2 - I have both spring force and spring constant, but no spring displacement.\n3 - I have both spring force and spring displacement, but no spring constant.\nAnswer: ");
				choice_springForce = read_int_choice();

				switch (choice_springForce) {
					case 1:
						printf("Tell me the spring constant (N/m):");
						fgets(get_springConstant, sizeof(get_springConstant), stdin);
						sscanf(get_springConstant, "%lf", &springConstant);

						printf("Tell me the spring displacement (m): ");
						fgets(get_springDisplacement, sizeof(get_springDisplacement), stdin);
						sscanf(get_springDisplacement, "%lf", &springDisplacement);

						springForce = calculate_springForce(springConstant, springDisplacement);

						printf("Spring Force = %.2lfN\n", springForce);
						break;
					case 2:
						printf("Tell me the spring force (N): ");
						fgets(get_springForce, sizeof(get_springForce), stdin);
						sscanf(get_springForce, "%lf", &springForce);

						printf("Tell me the spring constant (N/m): ");
						fgets(get_springConstant, sizeof(get_springConstant), stdin);
						sscanf(get_springConstant, "%lf", &springConstant);

						springDisplacement = calculate_springDisplacement_from_springForce(springForce, springConstant);

						printf("Spring Displacement = %.2lfm\n", springDisplacement);
						break;
					case 3:
						printf("Tell me the spring force (N): ");
						fgets(get_springForce, sizeof(get_springForce), stdin);
						sscanf(get_springForce, "%lf", &springForce);

						printf("Tell me the spring displacement (m): ");
						fgets(get_springDisplacement, sizeof(get_springDisplacement), stdin);
						sscanf(get_springDisplacement, "%lf", &springDisplacement);

						springConstant = calculate_springConstant_from_springForce(springForce, springDisplacement);

						printf("Spring Constant = %.2lfN/m\n", springConstant);
						break;
				}
				strcpy(get_springForce, "");
				strcpy(get_springConstant, "");
				strcpy(get_springDisplacement, "");
				break;
		} 

		printf("Do you want to calculate some more things? (Y/N) ");
		fgets(get_yes_no, sizeof(get_yes_no), stdin);
		sscanf(get_yes_no, "%c", &yes_no);
		yes_no = toupper(yes_no);
		getchar();

		if (yes_no == 'N') {
			printf("Bye then.\n");
		}

	}while(yes_no == 'Y');

	return 0;


}

f64 calculate_weightForce(f64 mass, f64 gravity) {
	if (mass < 0) {
		printf("You can't fucking calculate with negative mass, so I will give you 0.\n");
		return 0;
	}

	return mass * gravity;
}

f64 calculate_massFrom_weightForce(f64 force, f64 gravity) {
	if (force < 0) {
		printf("You can't have a negative force man. I'll just return 0, that's easier.\n");
		return 0;
	}

	return force / gravity; 
}

f64 calculate_gravityFrom_weightForce(f64 force, f64 mass) {
	if (force < 0 || mass < 0) {
		printf("Neither the force nor the mass can be equal to an negative number. Returning 0\n");
		return 0;
	}
	
	return force / mass;
}

f64 calculate_frictionForce(f64 friction_coeficient, f64 normal_force) {
	if (friction_coeficient < 0 || normal_force < 0) {
		printf("Man, neither the friction coeficient nor the normal force can be negative. Returning 0...\n");
		return 0;
	}

	return friction_coeficient * normal_force;
}

f64 calculate_frictionCoeficient_from_frictionForce(f64 frictionForce, f64 normal_force) {
	if (frictionForce < 0 || normal_force < 0) {
		printf("Man, the friction force nor the normal force can be negative. Returning 0.\n");
		return 0;
	}

	return frictionForce / normal_force;
}

f64 calculate_normalForce_from_frictionForce(f64 frictionForce, f64 friction_coeficient) {
	if (frictionForce < 0 || friction_coeficient < 0) {
		printf("Man, the friction force nor the friction coeficient can be negative. Returning 0.\n");
		return 0;
	}

	return frictionForce / friction_coeficient;
}

f64 calculate_springForce(f64 spring_constant, f64 spring_displacement) {
	if (spring_constant < 0 || spring_displacement < 0) {
		printf("Man, the sprint constant nor the sprint displacement can be negative. Returning 0.\n");
		return 0;
	}

	return spring_constant * spring_displacement;
}

f64 calculate_springConstant_from_springForce(f64 springForce, f64 spring_displacement) {
	if (springForce < 0 || spring_displacement < 0) {
		printf("Man, the spring force nor the spring displacement can be negative. Returning 0.\n");
		return 0;
	}

	return springForce / spring_displacement;
}

f64 calculate_springDisplacement_from_springForce(f64 springForce, f64 spring_constant) {
	if (springForce < 0 || spring_constant < 0) {
		printf("Man, the spring force nor the spring constant can be negative. Returning 0.\n");
		return 0;
	}

	return springForce / spring_constant; 
}
