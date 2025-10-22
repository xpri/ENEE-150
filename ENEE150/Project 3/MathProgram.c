#include <stdio.h>

// double *PointToAlpha;
// double *PointToBeta;

void add(double real1, double imag1, double real2, double imag2, double *resultRealPtr, double *resultImagPtr)
{
    *resultRealPtr = real1 + real2;
    *resultImagPtr = imag1 + imag2;
    // printf("this is the real result: %f\n", *resultRealPtr);
    printf("The finished sum is %f + %fi", *resultRealPtr, *resultImagPtr);
}

void subtract(double real1, double imag1, double real2, double imag2, double *resultRealPtr, double *resultImagPtr)
{
    *resultRealPtr = real1 - real2;
    *resultImagPtr = real1 - real2;
    printf("The finished sum is %f + %fi", *resultRealPtr, *resultImagPtr);
}

void multiply(double real1, double imag1, double real2, double imag2, double *resultRealPtr, double *resultImagPtr)
{
    
}

void readComplex(double *realPtr, double *imagPtr)
{
    printf("Please enter your real number: ");
    scanf("%lf", realPtr);
    // printf("This is the value of realPtr: %f\n", *realPtr);      //testing purposes
    printf("Please enter your complex number: ");
    scanf("%lf", imagPtr);
}

void printComplex(double real, double imag)
{

}

void main()
{
    double Alpha1;
    double Beta1;
    double Alpha2;
    double Beta2;
    double RealComponentResult;
    double ComplexComponentResult;

    //x = alpha + beta(i)

    readComplex(&Alpha1, &Beta1);      //makes the alpha1 and beta1
    // printf("%f\n", Alpha1);
    readComplex(&Alpha2, &Beta2);      //makes the alpha2 and beta2
    // printf("Testtwo\n");
    add(Alpha1, Beta1, Alpha2, Beta2, &RealComponentResult, &ComplexComponentResult);


}