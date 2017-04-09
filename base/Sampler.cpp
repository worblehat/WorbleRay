#include "Sampler.h"


Sampler::Sampler(unsigned short num_samples)
    : _num_samples(num_samples)
{

}

unsigned short Sampler::num_samples()
{
    return _num_samples;
}
