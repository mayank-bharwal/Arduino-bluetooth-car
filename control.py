import serial
import time

bluetooth_port = "07:12:05:15:60:07"  # Adjust this based on your Bluetooth connection
baud_rate = 9600

try:
    ser = serial.Serial(bluetooth_port, baud_rate, timeout=1)
    print("Connected to Bluetooth")

    while True:
        command = input("Enter command (F/B/L/R/S to move Forward/Backward/Left/Right/Stop): ").upper()
        ser.write(command.encode())
        time.sleep(0.1)

except KeyboardInterrupt:
    print("Exiting program")
    ser.close()
except Exception as e:
    print(f"Error: {e}")
    ser.close()
