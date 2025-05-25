# 🔢 Dynamic Sorting Algorithm Visualizer

A simple interactive C application using **OpenGL** and **GLUT** to visualize sorting algorithms in real-time. This project allows users to input an array and watch it being sorted using **Selection Sort** or **Bubble Sort**, with animated bar representations and statistics like time and space complexity.

## 🧠 Features

- Interactive user input for array size and values
- Visual real-time representation of:
  - **Selection Sort**
  - **Bubble Sort**
- Colored bar charts showing sorting progress
- Display of time and space complexity for each algorithm
- Re-initialize array anytime during runtime

## 🎮 Controls

| Key     | Function                     |
|--------|-------------------------------|
| `1`    | Start Selection Sort          |
| `2`    | Start Bubble Sort             |
| `r`    | Re-enter the array            |
| `Esc`  | Exit the application          |

## 🛠 Technologies Used

- **C**
- **OpenGL**
- **GLUT (OpenGL Utility Toolkit)**

## 🖥 Setup Instructions

### Windows (using GLUT):

1. **Install Dependencies**:
   - [FreeGLUT for Windows](http://freeglut.sourceforge.net/)
   - Add GLUT and OpenGL library files to your project settings (e.g., in Visual Studio)

2. **Compile & Run**:
   - Open the `.c` file in your preferred C IDE (e.g., Visual Studio)
   - Make sure `glut32.lib` and `opengl32.lib` are linked
   - Build and run the project

## 📸 Preview

![Sorting Visualizer Screenshot of Bubble Sort](https://github.com/eshabalaji/AlgoView/blob/b7eae5e4193a28e58f70bb0c5ea331154829cfe4/Bubble%20Sort.png)

## 📚 Learning Outcomes

- Understanding of sorting algorithms through visual feedback
- Basics of OpenGL rendering in C
- Event-driven programming with keyboard input
- Hands-on experience with real-time animation in C


