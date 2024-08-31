// Definir los pines del LED RGB en el Arduino Esplora
const int ledRojoPin = 9;   // Pin digital 9 para el componente rojo del LED RGB
const int ledVerdePin = 10; // Pin digital 10 para el componente verde del LED RGB
const int ledAzulPin = 11;  // Pin digital 11 para el componente azul del LED RGB

// Definir el pin del potenciómetro
const int potenciometroPin = A0; // Pin analógico A0 para el potenciómetro

void setup() {
  // Configurar los pines del LED RGB como salidas
  pinMode(ledRojoPin, OUTPUT);  // Configura el pin 9 como salida para el LED rojo
  pinMode(ledVerdePin, OUTPUT); // Configura el pin 10 como salida para el LED verde
  pinMode(ledAzulPin, OUTPUT);  // Configura el pin 11 como salida para el LED azul

  // Configurar el pin del potenciómetro como entrada
  // Aunque los pines analógicos se configuran automáticamente como entrada,
  // podemos especificar que A0 es de entrada si queremos ser explícitos.
  pinMode(potenciometroPin, INPUT); // Configura el pin A0 como entrada

  // Inicializar la comunicación serial a 9600 baudios para depuración
  Serial.begin(9600); // Establece la velocidad de comunicación serial a 9600 baudios
}

void loop() {
  // Leer el valor del potenciómetro (0 a 1023)
  int valorPotenciometro = analogRead(potenciometroPin); // Lee el valor del pin A0

  // Mapear el valor del potenciómetro a un rango de 0 a 255 para cada color
  int valorMapeado = map(valorPotenciometro, 0, 1023, 0, 255); // Mapea el valor de 0-1023 a 0-255

  // Asignar valores a los componentes del LED RGB
  int rojo = valorMapeado;       // Valor mapeado para el color rojo
  int verde = 255 - valorMapeado; // Complemento del valor mapeado para el color verde
  int azul = (valorMapeado / 2) % 256; // Escala azul para efectos visuales, ajustado a un rango de 0-255

  // Ajustar el color del LED RGB
  analogWrite(ledRojoPin, rojo);  // Ajusta la intensidad del color rojo en el pin 9
  analogWrite(ledVerdePin, verde); // Ajusta la intensidad del color verde en el pin 10
  analogWrite(ledAzulPin, azul);  // Ajusta la intensidad del color azul en el pin 11

  // Mostrar los valores en el monitor serial para depuración
  Serial.print("Valor Potenciometro: ");
  Serial.print(valorPotenciometro); // Imprime el valor leído del potenciómetro
  Serial.print(" -> Rojo: ");
  Serial.print(rojo); // Imprime la intensidad del color rojo
  Serial.print(", Verde: ");
  Serial.print(verde); // Imprime la intensidad del color verde
  Serial.print(", Azul: ");
  Serial.println(azul); // Imprime la intensidad del color azul

  // Esperar un poco antes de la próxima lectura
  delay(100); // Espera 100 milisegundos antes de la próxima iteración del loop
}

