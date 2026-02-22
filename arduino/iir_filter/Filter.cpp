#include "Filter.h"

// Legg til globale variabler etter behov her:
const float b[] = { 0, 0.00440564, 0.01502354, 0.00321789};
const float a[] = { 1, -2.37680206, 1.93293722, -0.53348809};

const int M = 3;

float x_buffer[M] = {};
float y_buffer[M] = {};

float filter(float x) {
  // Erstatt innholdet med kode som vil utfører filtrering av sample "x"
  float y = x * b[0];

  for (int i = 0; i < M; i++) {
    y += b[i + 1] * x_buffer[i] - a[i + 1] * y_buffer[i];
  }
  y /= a[0];

  // Oppdater buffer

  for (int i = M-1; i > 0; i--) {
    x_buffer[i] = x_buffer[i-1];
    y_buffer[i] = y_buffer[i-1];
  }
  x_buffer[0] = x;
  y_buffer[0] = y;

  // --------------------------------
  return y;
}
