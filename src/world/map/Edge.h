#pragma once

namespace sm
{
    struct Edge
    {
        int target_system_id;
        float distance;

        bool operator>(const Edge& other) const
        {
            return distance > other.distance;
        }
    };
}
