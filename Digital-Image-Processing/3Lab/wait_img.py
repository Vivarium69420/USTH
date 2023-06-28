import cv2

"""
    This module is used to wait for the user to press 'q' to close the image.
"""
def wait():
    while True:
        if cv2.waitKey(0) & 0xFF == ord('q'):
            break
    cv2.destroyAllWindows()
