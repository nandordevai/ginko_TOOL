/**
 * This tool generates a random, repeating stepped CV value.
 * The next value is output on each trigger.
 * Parameters:
 * 1: Random value range (works like an attenuator)
 * 2: Loop length (2, 3, 4, 6, 7, 8, 12, 16, 24, 32)
 * TR/G: next value
 * button: generate new values
 *
 * TODO: generate a rhythmical pattern where the distribution of notes
 * is based on input 1 (and use an external attenuator for scaling)
 *
 * NOTE: this code is untested.
 */

#include <TOOL.h>

#define TRIGGER 12

Tool tool;
int values[32];
int current_step = 0;
int last_step = 32;
int seq_lengths[] = {2, 3, 4, 6, 7, 8, 12, 16, 24, 32};
float value_scaling = 1;

void setup()
{
    /**
     * Generate the initial values & set trigger function.
     */
    generate();
    tool.set_trigger_input(trig);
}

void loop()
{
    /**
     * Set parameters based on input values here:
     * - generate new values on button press
     * - update scaling on input 1
     * - update length on input 2
     * map function scales values proportionally, since ADC in the
     * Arduino is 10bit, and our DAC is 12bit, we need to approximate
     * and compensate.
     */
    int cv1 = analogRead(1);
    value_scaling = map(cv1, 0, 1023, 0.1, 1);

    int cv2 = analogRead(2);
    int scaled_cv2 = map(cv2, 0, 1023, 0, 9);
    last_step = seq_lengths[scaled_cv2];

    int is_trig = digitalRead(TRIGGER);
    if (is_trig == LOW)
    {
        generate();
    }
}

void trig()
{
    /**
     * Generate output based on the next value and the current scaling.
     * Increase counter and reset when last step is reached.
     */
    tool.dac(values[current_step] * value_scaling);
    current_step++;
    if (current_step == last_step)
    {
        current_step = 0;
    }
}

void generate()
{
    /**
     * Generate the random values.
     */
    for (int i = 0; i < 32; i++)
    {
        values[i] = random(0, 2000);
    }
}
