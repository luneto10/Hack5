/**
 * Name: Luciano Carvalho (lguedesdecarvalhon2@huskers.unl.edu)
 *
 * Date: 2023 - 09 - 28
 *
 * Some utils formula header file
 */

/**
 * Takes a value in Degrees and return
 * the value in radians
 */
double degreesToRadians(double degree);

/**
 * Takes 4 values of latitude and longitude
 * and return the distance between these two
 * points.
 *
 */
double getAirDistance(double originLatitude, double originLongitude,
                      double destinationLatitude, double destinationLongitude);

/**
 * Takes the value of time and the percent of the speed
 * of the light and return the time dilation by Lorentz
 * Formula
 */
double lorentzTimeDilation(double t, double percentC);