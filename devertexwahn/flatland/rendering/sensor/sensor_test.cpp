/*
 *  SPDX-FileCopyrightText: 2022 Julian Amann <dev@vertexwahn.de>
 *  SPDX-License-Identifier: Apache-2.0
 */

#include "flatland/core/reference_counted.h"
#include "flatland/rendering/sensor/sensor.h"

#include "gmock/gmock.h"

using namespace flatland;

TEST(Film, to_string) {
    Film_ film{{{"width", 100}, {"height", 100}, {"filename", std::string("file.exr")}}};
    EXPECT_STREQ(film.to_string().c_str(), "Film");
}

TEST(Sensor, to_string) {
    PropertySet ps{{{"width", 100}, {"height", 100}, {"filename", std::string("file.exr")}}};
    ReferenceCounted<Film_> film = make_reference_counted<Film_>(ps);

    PropertySet ps_sensor{{"film", film}};
    Sensor2f sensor{ps_sensor};
    EXPECT_STREQ(sensor.to_string().c_str(), "SensorType");
}