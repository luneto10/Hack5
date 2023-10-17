/**
 * Name: Luciano Carvalho (lguedesdecarvalhon2@huskers.unl.edu)
 *
 * Date: 2023 - 09 - 28
 *
 * Some utils formula functions
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "utils.h"

#define EARTH_RADIUS 6371

double degreesToRadians(double degree)
{
    return (degree * M_PI) / 180;
}

double getAirDistance(double originLatitude,
                      double originLongitude,
                      double destinationLatitude,
                      double destinationLongitude)
{

    // Valitading the user input
    if (destinationLatitude > 90 || destinationLatitude < -90 || originLatitude > 90 || originLatitude < -90)
    {
        printf("\nPLEASE, ENTER A LATITUDE VALUE IN THE RANGE OF [-90,90]!\n\n");
        exit(1);
    }

    if (originLongitude < -180 || originLongitude > 180 || destinationLongitude < -180 || destinationLongitude > 180)
    {
        printf("\nPLEASE, ENTER A LONGITUDE VALUE IN THE RANGE OF [-180,180]!\n\n");
        exit(1);
    }

    // calculates the distance
    return acos(sin((originLatitude / 180) * M_PI) * sin((destinationLatitude / 180) * M_PI) + cos((destinationLatitude / 180) * M_PI) *
            cos((originLatitude / 180) * M_PI) * cos((destinationLongitude / 180) * M_PI - (originLongitude / 180) * M_PI)) * EARTH_RADIUS;
}

double lorentzTimeDilation(double t, double percentC)
{
    if (percentC > 1 || percentC < 0)
    {
        printf("ERROR: Enter a percent value between 0 and 1");
        exit(1);
    }
    if (t < 0)
    {
        printf("ERROR: Enter a positive time");
        exit(1);
    }

    return t / sqrt(1 - pow(percentC, 2));
}
