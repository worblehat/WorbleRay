#include "log.h"
#include "math.h"
#include "RegularSampler.h"

#include <cmath>


RegularSampler::RegularSampler(unsigned short num_samples)
    : Sampler(math::next_smaller_square_number(num_samples))
    , i(0)
{
    samples.reserve(_num_samples);

    float n = std::sqrt(_num_samples);
    float inv_n = 1.0f / n;
    float offset = inv_n / 2.0f;
    for(int x = 0; x < n; ++x)
    {
        for(int y = 0; y < n; ++y)
        {
            samples.push_back(PointD2(offset + x * inv_n, offset + y * inv_n));
        }
    }
}

const PointD2 &RegularSampler::next()
{
    if(i >= _num_samples)
    {
       i = 0;
    }
    return samples.at(i++);
}
