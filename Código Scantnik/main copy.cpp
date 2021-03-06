#include <Arduino.h>
#include "arm_math.h"
#include "sqrt_integer.h"

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=356,421
AudioMixer4              mixer1;         //xy=490,420
AudioSynthWaveformSine   sine1;          //xy=615,473
AudioFilterFIR           fir1;           //xy=616,421
AudioOutputI2S           i2s2;           //xy=667,312
AudioEffectMultiply      multiply1;      //xy=761,446
AudioFilterFIR           fir2; //xy=912,446
AudioRecordQueue         queue1;         //xy=1067,396
AudioConnection          patchCord1(i2s1, 0, mixer1, 0);
AudioConnection          patchCord2(i2s1, 1, mixer1, 1);
AudioConnection          patchCord3(mixer1, fir1);
AudioConnection          patchCord4(mixer1, 0, i2s2, 0);
AudioConnection          patchCord5(mixer1, 0, i2s2, 1);
AudioConnection          patchCord6(sine1, 0, multiply1, 1);
AudioConnection          patchCord7(fir1, 0, multiply1, 0);
AudioConnection          patchCord8(multiply1, fir2);
AudioConnection          patchCord9(fir2, queue1);
// GUItool: end automatically generated code

uint16_t HBP_NUM_COEFFICIENTS = 892;
int16_t HBP_COEFFICIENTS[892] = {76, -49, -38, -31, -26, -23, -19, -16, -12, -8, -4, 1, 5, 9, 13, 15, 16, 16, 14, 12, 8, 3, -2, -8, -13, -17, -20, -21, -21, -19, -15, -10, -4, 3, 10, 16, 21, 24, 26, 25, 23, 18, 12, 5, -3, -11, -19, -25, -29, -31, -31, -28, -22, -15, -6, 4, 13, 22, 29, 34, 37, 36, 33, 26, 18, 7, -4, -15, -25, -34, -40, -42, -42, -38, -30, -20, -9, 4, 17, 29, 38, 45, 48, 47, 43, 34, 23, 10, -4, -19, -32, -43, -50, -53, -53, -48, -38, -26, -11, 5, 20, 35, 46, 55, 58, 58, 52, 42, 29, 13, -4, -22, -37, -50, -59, -63, -62, -56, -45, -31, -14, 4, 22, 39, 53, 62, 66, 65, 59, 48, 33, 15, -4, -23, -40, -54, -64, -69, -68, -61, -50, -35, -16, 4, 23, 41, 55, 65, 70, 69, 63, 51, 35, 17, -3, -23, -41, -55, -65, -70, -69, -62, -51, -35, -17, 3, 22, 39, 53, 63, 68, 67, 61, 49, 34, 17, -2, -20, -37, -50, -60, -64, -63, -57, -47, -32, -16, 1, 18, 34, 46, 54, 58, 57, 52, 42, 29, 15, -1, -16, -29, -40, -47, -50, -49, -44, -36, -25, -13, 0, 13, 24, 32, 38, 40, 39, 35, 28, 20, 10, 0, -9, -17, -23, -27, -28, -27, -24, -19, -13, -6, -0, 5, 10, 12, 14, 14, 12, 10, 7, 5, 2, 0, -1, -1, -0, 1, 3, 4, 5, 6, 5, 3, 0, -4, -8, -13, -17, -21, -23, -23, -20, -16, -9, -1, 9, 19, 28, 35, 41, 43, 42, 36, 28, 16, 2, -14, -29, -43, -55, -62, -65, -62, -54, -41, -23, -3, 19, 40, 60, 75, 85, 88, 84, 72, 55, 31, 4, -24, -52, -76, -96, -108, -112, -106, -92, -69, -40, -7, 29, 63, 93, 117, 132, 136, 129, 112, 84, 49, 9, -33, -74, -110, -138, -156, -161, -153, -132, -100, -59, -12, 38, 85, 127, 159, 179, 185, 176, 152, 115, 68, 15, -42, -95, -143, -179, -202, -209, -199, -172, -131, -78, -18, 45, 105, 158, 199, 224, 232, 220, 191, 146, 88, 21, -47, -114, -172, -216, -244, -253, -241, -209, -160, -97, -25, 50, 121, 184, 232, 263, 272, 259, 225, 173, 105, 29, -51, -127, -194, -246, -279, -289, -276, -240, -184, -113, -33, 52, 132, 203, 258, 292, 303, 290, 252, 195, 121, 36, -52, -136, -210, -267, -303, -315, -301, -263, -203, -127, -40, 51, 138, 214, 273, 311, 323, 309, 270, 210, 132, 43, -50, -139, -216, -277, -315, -328, -314, -275, -214, -135, -46, 48, 138, 216, 278, 316, 330, 316, 278, 216, 138, 48, -46, -135, -214, -275, -314, -328, -315, -277, -216, -139, -50, 43, 132, 210, 270, 309, 323, 311, 273, 214, 138, 51, -40, -127, -203, -263, -301, -315, -303, -267, -210, -136, -52, 36, 121, 195, 252, 290, 303, 292, 258, 203, 132, 52, -33, -113, -184, -240, -276, -289, -279, -246, -194, -127, -51, 29, 105, 173, 225, 259, 272, 263, 232, 184, 121, 50, -25, -97, -160, -209, -241, -253, -244, -216, -172, -114, -47, 21, 88, 146, 191, 220, 232, 224, 199, 158, 105, 45, -18, -78, -131, -172, -199, -209, -202, -179, -143, -95, -42, 15, 68, 115, 152, 176, 185, 179, 159, 127, 85, 38, -12, -59, -100, -132, -153, -161, -156, -138, -110, -74, -33, 9, 49, 84, 112, 129, 136, 132, 117, 93, 63, 29, -7, -40, -69, -92, -106, -112, -108, -96, -76, -52, -24, 4, 31, 55, 72, 84, 88, 85, 75, 60, 40, 19, -3, -23, -41, -54, -62, -65, -62, -55, -43, -29, -14, 2, 16, 28, 36, 42, 43, 41, 35, 28, 19, 9, -1, -9, -16, -20, -23, -23, -21, -17, -13, -8, -4, 0, 3, 5, 6, 5, 4, 3, 1, -0, -1, -1, 0, 2, 5, 7, 10, 12, 14, 14, 12, 10, 5, -0, -6, -13, -19, -24, -27, -28, -27, -23, -17, -9, 0, 10, 20, 28, 35, 39, 40, 38, 32, 24, 13, 0, -13, -25, -36, -44, -49, -50, -47, -40, -29, -16, -1, 15, 29, 42, 52, 57, 58, 54, 46, 34, 18, 1, -16, -32, -47, -57, -63, -64, -60, -50, -37, -20, -2, 17, 34, 49, 61, 67, 68, 63, 53, 39, 22, 3, -17, -35, -51, -62, -69, -70, -65, -55, -41, -23, -3, 17, 35, 51, 63, 69, 70, 65, 55, 41, 23, 4, -16, -35, -50, -61, -68, -69, -64, -54, -40, -23, -4, 15, 33, 48, 59, 65, 66, 62, 53, 39, 22, 4, -14, -31, -45, -56, -62, -63, -59, -50, -37, -22, -4, 13, 29, 42, 52, 58, 58, 55, 46, 35, 20, 5, -11, -26, -38, -48, -53, -53, -50, -43, -32, -19, -4, 10, 23, 34, 43, 47, 48, 45, 38, 29, 17, 4, -9, -20, -30, -38, -42, -42, -40, -34, -25, -15, -4, 7, 18, 26, 33, 36, 37, 34, 29, 22, 13, 4, -6, -15, -22, -28, -31, -31, -29, -25, -19, -11, -3, 5, 12, 18, 23, 25, 26, 24, 21, 16, 10, 3, -4, -10, -15, -19, -21, -21, -20, -17, -13, -8, -2, 3, 8, 12, 14, 16, 16, 15, 13, 9, 5, 1, -4, -8, -12, -16, -19, -23, -26, -31, -38, -49};

uint16_t HLP_NUM_COEFFICIENTS = 28;
int16_t HLP_COEFFICIENTS[28] = {39, 84, 163, 280, 439, 640, 880, 1149, 1433, 1715, 1974, 2190, 2345, 2427, 2427, 2345, 2190, 1974, 1715, 1433, 1149, 880, 640, 439, 280, 163, 84, 39};
 
void setup() {

  Serial.begin(2000000);
  mixer1.gain(1, 10.0);
  mixer1.gain(2, 10.0);
  sine1.amplitude(1);
  sine1.frequency(1913.83);
  fir1.begin(HBP_COEFFICIENTS, HBP_NUM_COEFFICIENTS);
  fir2.begin(HLP_COEFFICIENTS, HLP_NUM_COEFFICIENTS);
  queue1.begin();
  AudioMemory(16);

}
int16_t fft_input[1024];
uint8_t new_sample_counter = 0;

/*

// 140312 - PAH - slightly faster copy
static void copy_to_fft_buffer(void *destination, const void *source)
{
	const uint16_t *src = (const uint16_t *)source;
	uint32_t *dst = (uint32_t *)destination;

	for (int i=0; i < AUDIO_BLOCK_SAMPLES; i++) {
		*dst++ = *src++;  // real sample plus a zero for imaginary
	}
}

arm_cfft_radix4_instance_q15 fft_inst;
int16_t buffer[2048] __attribute__ ((aligned (4)));
uint16_t output[512] __attribute__ ((aligned (4)));
*/


void loop() {
  if(queue1.available()){
    
    int16_t* packet = queue1.readBuffer();

    Serial.println(packet[0]);

    queue1.freeBuffer();
    
    /*for (size_t i = 99; i >= 1; i--) {
      fft_input[i] = fft_input[i-1];
    }
    fft_input[0] = packet[0];
    new_sample_counter++;  

    queue1.freeBuffer();

    Serial.println("Test");*/

  
  }

  if(new_sample_counter > 300) {
    new_sample_counter = 0;
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
    Serial.println("procesando");
    //FFT;

    copy_to_fft_buffer(buffer+0x000, fft_input);
		copy_to_fft_buffer(buffer+0x100, fft_input);
		copy_to_fft_buffer(buffer+0x200, fft_input);
		copy_to_fft_buffer(buffer+0x300, fft_input);
		copy_to_fft_buffer(buffer+0x400, fft_input);
		copy_to_fft_buffer(buffer+0x500, fft_input);
		copy_to_fft_buffer(buffer+0x600, fft_input);
		copy_to_fft_buffer(buffer+0x700, fft_input);

    arm_cfft_radix4_q15(&fft_inst, buffer);

    for (int i=0; i < 512; i++) {
      uint32_t tmp = *((uint32_t *)buffer + i); // real & imag
      uint32_t magsq = multiply_16tx16t_add_16bx16b(tmp, tmp);
      output[i] = sqrt_uint32_approx(magsq);
      Serial.print(output[i]);
      Serial.print(",");
    }
    Serial.println("test");
    
    
    digitalWrite(13, LOW);
  }

 // Serial.print("sample_Counter: ");
  //Serial.println(new_sample_counter);
} 