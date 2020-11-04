/*******************************************************************************
 * Program:	Bisection Search Method
 * Purpose:	Allows you to find optimal solution with Bisection Heuristic Method.
 * Author:		Ege Demirbas 
 * Version: 	0 
********************************************************************************/
package com.example;

public class Main
{
    public static void main(String[] args)
    {
        //params
        float b = 10;
        float a = (float) 0.1;
        float e = (float) 0.001;

        //main func
        float x = 0;
        float fx;
        float fxx;
        while((b-a) >= e)
        {
            x = (a+b)/2;
            fx = x + 1/x;
            fxx = (x+e) + 1/(x+e);
            if(fx >= fxx)
            {
                a = x;
            }
            else
            {
                b = x;
            }
        }

        System.out.println(x + "is a local minimum of f(x) with " + e + " e approximation.");
    }
}



