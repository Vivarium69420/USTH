import cv2
import numpy as np
import wait_img as wi

# Read image
img = cv2.imread("incredible.jpg", cv2.IMREAD_GRAYSCALE)

# apply canny filter

dst = cv2.Canny(img, 50, 200, None, 3)

# Copy edges to the images that will display the results in BGR
cdst = cv2.cvtColor(dst, cv2.COLOR_GRAY2BGR)

"""
Explaination from OpenCV documentation:
A line can be detected by finding the number of intersections between curves.
The more curves intersecting means that the line represented by that intersection have more points. 
We can define a threshold of the minimum number of intersections needed to detect a line
"""

# apply HoughLines filter
lines = cv2.HoughLines(dst, 1, np.pi / 180, 150, None, 0, 0)
if lines is not None:
    for line in lines:
        rho, theta = line[0]
        a = np.cos(theta)
        b = np.sin(theta)
        x0 = rho * a
        y0 = rho * b
        x1 = int(x0 + 1000 * (-b))
        y1 = int(y0 + 1000 * (a))
        x2 = int(x0 - 1000 * (-b))
        y2 = int(y0 - 1000 * (a))

        cv2.line(cdst, (x1, y1), (x2, y2), (0, 0, 255), 2)

# display image
cv2.imshow("Original", img)
cv2.imshow("Lines", cdst)

wi.wait()
