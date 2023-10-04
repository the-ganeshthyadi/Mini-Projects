#include <stdio.h>
#include <math.h>

int main() {
    char operator;
    double num1, num2, result;

    
    printf("Enter an operator (+, -, *, /, ^, sqrt, %%): ");
    scanf(" %c", &operator);

    
    switch (operator) {
        case '+':
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            break;
        case '-':
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            break;
        case '*':
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            break;
        case '/':
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero\n");
                return 1; 
            }
            break;
        case '^':
            printf("Enter base and exponent: ");
            scanf("%lf %lf", &num1, &num2);
            result = pow(num1, num2);
            break;
        case 's':
            printf("Enter a number: ");
            scanf("%lf", &num1);
            if (num1 >= 0) {
                result = sqrt(num1);
            } else {
                printf("Error: Can't     calculate square root of a negative number\n");
                return 1; 
            }
            break;
        case '%':
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            if (num2 != 0) {
                result = fmod(num1, num2);
            } else {
                printf("Error: Modulus by zero\n");
                return 1; 
            }
            break;
        default:
            printf("Error: Invalid operator\n");
            return 1; 
    }

    printf("Result: %lf\n", result);

    return 0;
}
