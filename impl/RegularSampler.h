#ifndef REGULARSAMPLER_H
#define REGULARSAMPLER_H

#include "PointD2.h"
#include "Sampler.h"

#include <vector>


/*!
 * \brief Samples a uniform square in a regular grid.
 * The number of samples is always a square number.
 * If the given number of samples is not a square number, it is
 * automatically reduced to the next smaller square number.
 */
class RegularSampler : public Sampler
{
public:
    explicit RegularSampler(unsigned short num_samples);

    const PointD2 &next() override;

private:
    //! Index of the last sample returned
    unsigned short i;
    std::vector<PointD2> samples;
};

#endif // REGULARSAMPLER_H
