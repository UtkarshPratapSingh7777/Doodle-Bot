# Doodle-Bot

**Doodle-Bot** is an automated drawing robot developed for the **Robomania** event at **Avishkar, MNNIT (2024)**.  
It uses image processing to convert digital images into coordinate-based instructions that control a robot to sketch the image.

---

## ✨ Features

- Converts digital images into coordinate paths for robotic movement  
- Generates real-time drawing instructions based on processed image data  
- Automates precise sketching using motor control via Arduino  

---

## 🛠️ Technologies Used

- **Python** – Image processing & path generation  
- **OpenCV** – Extracting and analyzing drawing paths  
- **Arduino** – Executing movement commands to control motors  

---

## 📂 Repository Contents

- `sketch_nov11a.ino` → Arduino sketch to control the motors  
- `Steel_Surgeons.py` → Python script for image processing & path generation  

---

## 🚀 Getting Started

### Requirements

- Python 3.x  
- OpenCV (`pip install opencv-python`)  
- Arduino IDE  
- Arduino-compatible board (e.g., Uno, Nano)  
- Motor driver shield or equivalent  

### Installation & Setup

```bash
git clone https://github.com/UtkarshPratapSingh7777/Doodle-Bot.git
cd Doodle-Bot
pip install opencv-python
```

1. Upload sketch_nov11a.ino to your Arduino board via Arduino IDE.
2. Run the Python script:
  ```bash
  python Steel_Surgeons.py
```
3. The bot will draw based on the generated coordinate path.


### USAGE
🎨 Usage

1.Provide a digital image (preferably grayscale / line art)

2.The Python script processes it into (x, y) coordinates

3.Coordinates are sent to Arduino via serial communication

4.The robot sketches the image using stepper/servo motors
