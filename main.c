#include<stdio.h>
#include<math.h>
#include "rlc.h"
#define pi 3.142

int main(void)
{
    // declare variable list
    double r,l,c,f,v;
    double Xc,Xl,z,rms_i,res_f,Vs,P;

    // prompt user to enter circuit information
    printf("Enter the value of Resistor(unit in ohm): ");
    scanf("%lf",&r);
    printf("Enter the value of Inductor(unit in henry): ");
    scanf("%lf",&l);
    printf("Enter the value of Capacitor(unit in farad): ");
    scanf("%lf",&c);
    printf("Enter the value of Source Voltage(unit in volt): ");
    scanf("%lf",&v);
    printf("Enter the value of AC Frequency(unit in Hertz): ");
    scanf("%lf",&f);

    // call function to perform RLC circuit calculation
    Cal_impedance(f*c,f*l,r,&Xc,&Xl,&z);
    rms_i=Cal_RMS_current(z,v);
    Vs=Cal_series_voltage(r,Xc,Xl,rms_i);
    P=Cal_power(rms_i,r);
    res_f=Cal_Res_frequency(l,c);
    printf("\n");

    printf("************************ SOLUTION ************************\n\n");
    // Print out the solution
    printf("the value of XC, capacitive reactance:%f ohms\n",Xc);
    printf("the value of XL, inductance reactance:%f ohms\n",Xl);
    printf("the value of Z, impedance:%f ohms\n",z);
    printf("the value of Irms, rms current:%f ampere\n",rms_i);
    printf("the value of Vs, series voltage:%f volt\n",Vs);
    printf("the value of P, power consumed:%f watts\n",P);
    printf("the value of res_F, resonant frequency:%f hertz\n",res_f);
    printf("\n**********************************************************\n");
}


