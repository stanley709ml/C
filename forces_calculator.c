#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef float f32;
typedef double f64;


// Weight Force

typedef struct {
	char get_weightForce[20];
	char get_mass[20];
	char get_gravity[20];
	int choice_weightForce;
	f64 weightForce;
	f64 mass;
	f64 gravity;
} Weight_Force;

f64 calculate_weightForce(f64 mass, f64 gravity);
f64 calculate_massFrom_weightForce(f64 force, f64 gravity);
f64 calculate_gravityFrom_weightForce(f64 force, f64 mass);

// End Weight Force

// ---------------- //

// Friction Force

typedef struct {
	char get_frictionForce[20];
	char get_frictionConstant[20];
	char get_normalForce[20];
	int choice_frictionForce;
	f64 frictionForce;
	f64 frictionConstant;
	f64 normalForce;
} Friction_Force;

f64 calculate_frictionForce(f64 friction_coeficient, f64 normal_force);
f64 calculate_frictionCoeficient_from_frictionForce(f64 frictionForce, f64 normal_force);
f64 calculate_normalForce_from_frictionForce(f64 frictionForce, f64 friction_coeficient);

// End Friction Force

// ---------------- // 

// Elastic Force

typedef struct {
	char get_springForce[20];
	char get_springConstant[20];
	char get_springDisplacement[20];
	int choice_springForce;
	f64 springForce;
	f64 springConstant;
	f64 springDisplacement;
} Elastic_Force;

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
				Weight_Force weight_force;

				printf("Firsts firsts, tell me what do you already have:\n1 - I have both mass and gravity, but no force yet\n2 - I have both force and gravity, but no mass\n3 - I have both force and mass, but no gravity.\nAnswer: ");
				weight_force.choice_weightForce = read_int_choice();

				switch (weight_force.choice_weightForce) {
					case 1:
						printf("Tell me the mass (kg): ");
						fgets(weight_force.get_mass, sizeof(weight_force.get_mass), stdin);
						sscanf(weight_force.get_mass, "%lf", &weight_force.mass);
				
						printf("Tell me the gravity (m/s^2): ");
						fgets(weight_force.get_gravity, sizeof(weight_force.get_gravity), stdin);
						sscanf(weight_force.get_gravity, "%lf", &weight_force.gravity);

						weight_force.weightForce = calculate_weightForce(weight_force.mass, weight_force.gravity);

						printf("Weight Force = %.2lfN\n", weight_force.weightForce);
						break;
					case 2:
						printf("Tell me the force (N): ");
						fgets(weight_force.get_weightForce, sizeof(weight_force.get_weightForce), stdin);
						sscanf(weight_force.get_weightForce, "%lf", &weight_force.weightForce);

						printf("Tell me the gravity (m/s^2): ");
						fgets(weight_force.get_gravity, sizeof(weight_force.get_gravity), stdin);
						sscanf(weight_force.get_gravity, "%lf", &weight_force.gravity);

						weight_force.gravity = calculate_massFrom_weightForce(weight_force.weightForce, weight_force.gravity);

						printf("Mass = %.2lfkg\n", weight_force.gravity);
						break;
					case 3:
						printf("Tell me the force (N): ");
						fgets(weight_force.get_weightForce, sizeof(weight_force.get_weightForce), stdin);
						sscanf(weight_force.get_weightForce, "%lf", &weight_force.weightForce);

						printf("Tell me the mass (kg): ");
						fgets(weight_force.get_mass, sizeof(weight_force.get_mass), stdin);
						sscanf(weight_force.get_mass, "%lf", &weight_force.mass);

						weight_force.gravity = calculate_gravityFrom_weightForce(weight_force.weightForce, weight_force.mass);

						printf("Gravity = %.2lfm/s^2\n", weight_force.gravity);
						break;
					}
				strcpy(weight_force.get_weightForce, "");
				strcpy(weight_force.get_mass, "");
				strcpy(weight_force.get_gravity, "");
				break;
		
			case 2:
				Friction_Force friction_force;

				printf("Firsts firsts, tell me what do you already have:\n1 - I have both friction constant and normal force, but no friction force yet\n2 - I have both friction force and friction constant, but no normal force.\n3 - I have both friction force and normal force, but no friction constant.\nAnswer: ");
				friction_force.choice_frictionForce = read_int_choice();

				switch (friction_force.choice_frictionForce) {
					case 1:
						printf("Tell me the friction constant (N/m): ");
						fgets(friction_force.get_frictionConstant, sizeof(friction_force.get_frictionConstant), stdin);
						sscanf(friction_force.get_frictionConstant, "%lf", &friction_force.frictionConstant);

						printf("Tell me the normal force (N): ");
						fgets(friction_force.get_normalForce, sizeof(friction_force.get_normalForce), stdin);
						sscanf(friction_force.get_normalForce, "%lf", &friction_force.normalForce);

						friction_force.frictionForce = calculate_frictionForce(friction_force.frictionConstant, friction_force.normalForce);

						printf("Friction Force = %.2lfN\n", friction_force.frictionForce);
						break;
					case 2:
						printf("Tell me the friction force (N): ");
						fgets(friction_force.get_frictionForce, sizeof(friction_force.get_frictionForce), stdin);
						sscanf(friction_force.get_frictionForce, "%lf", &friction_force.frictionForce);

						printf("Tell me the friction constant (N/m): ");
						fgets(friction_force.get_frictionConstant, sizeof(friction_force.get_frictionConstant), stdin);
						sscanf(friction_force.get_frictionConstant, "%lf", &friction_force.frictionConstant);

						friction_force.normalForce = calculate_normalForce_from_frictionForce(friction_force.frictionForce, friction_force.frictionConstant);

						printf("Normal Force = %.2lfN\n", friction_force.normalForce);
						break;
					case 3:
						printf("Tell me the friction force (N): ");
						fgets(friction_force.get_frictionForce, sizeof(friction_force.get_frictionForce), stdin);
						sscanf(friction_force.get_frictionForce, "%lf", &friction_force.frictionForce);

						printf("Tell me the normal force (N): ");
						fgets(friction_force.get_normalForce, sizeof(friction_force.get_normalForce), stdin);
						sscanf(friction_force.get_normalForce, "%lf", &friction_force.normalForce);

						friction_force.frictionConstant = calculate_frictionCoeficient_from_frictionForce(friction_force.frictionForce, friction_force.normalForce);

						printf("Friction Constant = %.2lfn/m\n", friction_force.frictionConstant);
						break;
					}
				strcpy(friction_force.get_frictionForce, "");
				strcpy(friction_force.get_frictionConstant, "");
				strcpy(friction_force.get_normalForce, "");
				break;

			case 3:
				Elastic_Force elastic_force;
				
				printf("Firsts firsts, tell me what do you already have:\n1 - I have both spring constant and spring displacement, but no spring force yet\n2 - I have both spring force and spring constant, but no spring displacement.\n3 - I have both spring force and spring displacement, but no spring constant.\nAnswer: ");
				elastic_force.choice_springForce = read_int_choice();

				switch (elastic_force.choice_springForce) {
					case 1:
						printf("Tell me the spring constant (N/m):");
						fgets(elastic_force.get_springConstant, sizeof(elastic_force.get_springConstant), stdin);
						sscanf(elastic_force.get_springConstant, "%lf", &elastic_force.springConstant);

						printf("Tell me the spring displacement (m): ");
						fgets(elastic_force.get_springDisplacement, sizeof(elastic_force.get_springDisplacement), stdin);
						sscanf(elastic_force.get_springDisplacement, "%lf", &elastic_force.springDisplacement);

						elastic_force.springForce = calculate_springForce(elastic_force.springConstant, elastic_force.springDisplacement);

						printf("Spring Force = %.2lfN\n", elastic_force.springForce);
						break;
					case 2:
						printf("Tell me the spring force (N): ");
						fgets(elastic_force.get_springForce, sizeof(elastic_force.get_springForce), stdin);
						sscanf(elastic_force.get_springForce, "%lf", &elastic_force.springForce);

						printf("Tell me the spring constant (N/m): ");
						fgets(elastic_force.get_springConstant, sizeof(elastic_force.get_springConstant), stdin);
						sscanf(elastic_force.get_springConstant, "%lf", &elastic_force.springConstant);

						elastic_force.springDisplacement = calculate_springDisplacement_from_springForce(elastic_force.springForce, elastic_force.springConstant);

						printf("Spring Displacement = %.2lfm\n", elastic_force.springDisplacement);
						break;
					case 3:
						printf("Tell me the spring force (N): ");
						fgets(elastic_force.get_springForce, sizeof(elastic_force.get_springForce), stdin);
						sscanf(elastic_force.get_springForce, "%lf", &elastic_force.springForce);

						printf("Tell me the spring displacement (m): ");
						fgets(elastic_force.get_springDisplacement, sizeof(elastic_force.get_springDisplacement), stdin);
						sscanf(elastic_force.get_springDisplacement, "%lf", &elastic_force.springDisplacement);

						elastic_force.springConstant = calculate_springConstant_from_springForce(elastic_force.springForce, elastic_force.springDisplacement);

						printf("Spring Constant = %.2lfN/m\n", elastic_force.springConstant);
						break;
				}
				strcpy(elastic_force.get_springForce, "");
				strcpy(elastic_force.get_springConstant, "");
				strcpy(elastic_force.get_springDisplacement, "");
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
