#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <math.h>

#include "utils.h"
#include "include/cmocka.h"

static void degreesToRadiansTest(void **state)
{
    double *values = *((double **)state);
    double degrees = values[0];
    assert_float_equal(degreesToRadians(degrees), values[1], 0.000001);
}

static void getAirDistanceTest(void **state)
{
    double *values = *((double **)state);
    double oLatitude = values[0];
    double oLongitude = values[1];
    double dLatitude = values[2];
    double dLongitude = values[3];
    assert_float_equal(getAirDistance(oLatitude, oLongitude, dLatitude, dLongitude), values[4], 1);
}

int main(void)
{
    double degreesToRadiansTestCases[][2] = {
        {0.0, 0.0},
        {30.0, M_PI / 6.0},
        {45.0, M_PI_4},
        {60.0, M_PI / 3.0},
        {90.0, M_PI_2},
        {120.0, 2.0 * M_PI / 3.0},
        {135.0, 3.0 * M_PI / 4.0},
        {150.0, 5.0 * M_PI / 6.0},
        {180.0, M_PI},
        {210.0, 7.0 * M_PI / 6.0},
        {225.0, 5.0 * M_PI / 4.0},
        {240.0, 4.0 * M_PI / 3.0},
        {270.0, 3.0 * M_PI / 2.0},
        {300.0, 5.0 * M_PI / 3.0},
        {315.0, 7.0 * M_PI / 4.0},
        {330.0, 11.0 * M_PI / 6.0},
        {360.0, 2.0 * M_PI},
        {-45.0, -M_PI_4},
        {-90.0, -M_PI_2},
        {-135.0, -3.0 * M_PI / 4},
    };

    double getAirDistanceTestCase[][5] = {
        {0.0, 0.0, 0.0, 0.0, 0.0},                                   // Test case: Both points at the same location (0 distance)
        {51.500000,-0.166670, -15.793404,-47.882317, 8789.52},                          // Test case: North pole to equator
        {56.728621973140754,-4.532377509931962, 52.37559917665913,8.42837360530541, 963.64},                         // Test case: South pole to equator
        {56.728621973140754,-4.532377509931962, 63.174193604205094,16.6896909629462, 1372.36},                         // Test case: Around the Earth's equator
        {16.97274101999902,9.114344363425744, 72.01972876525514,99.97140641871704, 8244.29},         // Test case: New York to Los Angeles
    };

    const struct CMUnitTest tests[] = {

        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[0]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[1]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[2]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[3]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[4]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[5]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[6]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[7]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[8]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[9]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[10]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[11]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[12]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[13]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[14]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[15]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[16]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[17]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[18]),
        cmocka_unit_test_prestate(degreesToRadiansTest, &degreesToRadiansTestCases[19]),

        cmocka_unit_test_prestate(getAirDistanceTest, &getAirDistanceTestCase[0]),
        cmocka_unit_test_prestate(getAirDistanceTest, &getAirDistanceTestCase[1]),
        cmocka_unit_test_prestate(getAirDistanceTest, &getAirDistanceTestCase[2]),
        cmocka_unit_test_prestate(getAirDistanceTest, &getAirDistanceTestCase[3]),
        cmocka_unit_test_prestate(getAirDistanceTest, &getAirDistanceTestCase[4]),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
