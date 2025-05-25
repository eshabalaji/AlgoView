#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define ARRAY_SIZE 10
int arr[ARRAY_SIZE];
int size = 0;
int i = 0, j = 0, minIndex = 0;
bool sorting = false;
int algorithm = -1; // -1: No algorithm, 0: Selection Sort, 1: Bubble Sort
int iterations = 0;
void drawText(float x, float y, const char* text) {
	glRasterPos2f(x, y);
	for (const char* c = text; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}
void initializeArray() {
	printf("Enter the size of array:");
	scanf_s("%d", &size);
	printf("Enter %d elements of the array (space-separated):\n", size);
	for (int k = 0; k < size; k++) {
		scanf_s("%d", &arr[k]);
	}
	i = j = minIndex = 0;
	sorting = false;
	iterations = 0;
}
void displayText() {
	drawText(-0.9, 0.9, "DYNAMIC SORTING ALGORITHM VISUALIZER");
	glBegin(GL_LINES);
	glVertex2f(-0.9, 0.87);
	glVertex2f(0.9, 0.87);
	glEnd();
	drawText(-0.9, 0.75, "MENU:");
	drawText(-0.9, 0.7, "'1' - Selection Sort");
	drawText(-0.9, 0.65, "'2' - Bubble Sort");
	drawText(-0.9, 0.6, "'r' - Re-enter Array");
	drawText(-0.9, 0.55, "'Esc' - Quit");
	if (sorting) {
		drawText(-0.9, 0.4, "Sorting in progress...");
	}
	else if (algorithm != -1) {
		char result[100];
		sprintf_s(result, sizeof(result), "Sorting complete! Iterations: %d", iterations);
		drawText(-0.9, 0.4, result);
		if (algorithm == 0) {
			drawText(-0.9, 0.3, "Time Complexity: O(n^2)");
			drawText(-0.9, 0.25, "Space Complexity: O(1)");
		}
		else if (algorithm == 1) {
			drawText(-0.9, 0.3, "Time Complexity: O(n^2)");
			drawText(-0.9, 0.25, "Space Complexity: O(1)");
		}
		drawText(-0.9, 0.2, "Press 'r' to Re-enter Array.");
	}
}
void displayArray() {
	for (int k = 0; k < size; k++) {
		if (algorithm == 0) { // Selection Sort visualization
			if (k == i)
				glColor3f(0.0, 0.0, 1.0); // Current position (blue)
			else if (k == minIndex)
				glColor3f(1.0, 0.0, 0.0); // Minimum found (red)
			else if (k < i)
				glColor3f(0.0, 1.0, 0.0); // Sorted part (green)
			else
				glColor3f(0.8, 0.8, 0.8); // Unsorted part (gray)
		}
		else if (algorithm == 1) { // Bubble Sort visualization
			if (k == j || k == j + 1)
				glColor3f(1.0, 0.0, 0.0); // Comparing (red)
			else if (k >= size - i - 1)
				glColor3f(0.0, 1.0, 0.0); // Sorted part (green)
			else
				glColor3f(0.8, 0.8, 0.8); // Unsorted part (gray)
		}
		else {
			glColor3f(0.8, 0.8, 0.8); // Default (gray)
		}
		glBegin(GL_QUADS);
		glVertex2f(-0.9 + k * 1.8 / size, -0.9);
		glVertex2f(-0.9 + k * 1.8 / size + 1.5 / size, -0.9);
		glVertex2f(-0.9 + k * 1.8 / size + 1.5 / size, -0.9 + arr[k] / 100.0);
		glVertex2f(-0.9 + k * 1.8 / size, -0.9 + arr[k] / 100.0);
		glEnd();
		// Draw labels for the numbers above the bars
		char label[10];
		sprintf_s(label, sizeof(label), "%d", arr[k]);
		glColor3f(0.0, 0.0, 0.0); // Black text
		drawText(-0.9 + k * 1.8 / size + 0.05, -0.9 + arr[k] / 100.0 + 0.05, label);
	}
}void selectionSortStep() {
	if (i < size - 1) {
		if (j < size) {
			if (arr[j] < arr[minIndex])
				minIndex = j;
			j++;
		}
		else {
			// Swap the current element with the smallest element found
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
			i++;
			j = i + 1;
			minIndex = i;
		}
		iterations++; // Count each comparison
	}
	else {
		sorting = false; // Sorting complete
	}
}
void bubbleSortStep() {
	if (i < size - 1) {
		if (j < size - i - 1) {
			if (arr[j] > arr[j + 1]) {
				// Swap adjacent elements
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}j++;
		}
		else {
			i++;
			j = 0;
		}
		iterations++; // Count each comparison
	}
	else {
		sorting = false; // Sorting complete
	}
}
void timerFunc(int value) {
	if (sorting) {
		if (algorithm == 0) {
			selectionSortStep();
		}
		else if (algorithm == 1) {
			bubbleSortStep();
		}
		glutPostRedisplay();
		glutTimerFunc(300, timerFunc, 0); // Call every 300 ms
	}
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	displayText();
	displayArray();
	glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27: exit(0); // Exit on 'Esc'
	case '1': algorithm = 0; sorting = true; i = j = 0; minIndex = 0; iterations = 0;
		glutTimerFunc(0, timerFunc, 0); break; // Selection Sort
	case '2': algorithm = 1; sorting = true; i = j = 0; iterations = 0; glutTimerFunc(0,
		timerFunc, 0); break; // Bubble Sort
	case 'r': initializeArray(); break; // Re-enter Array
	}
	glutPostRedisplay();
}
void initOpenGL() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv) {
	printf("Welcome to the Dynamic Sorting Algorithm Visualizer!\n");
	initializeArray();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Dynamic Sorting Algorithm Visualizer");
	initOpenGL();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}