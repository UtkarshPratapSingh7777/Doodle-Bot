import cv2 as cv
import numpy as np
def sign(x):
    return int(x > 0) - int(x < 0)
image = cv.imread('test_image_2.png')
if image is None:
    raise ValueError("Image not found. Please check the path.")

gray = cv.cvtColor(cv.resize(image, (int(image.shape[0] * 0.75), int(image.shape[1] * 0.75)), interpolation=cv.INTER_CUBIC), cv.COLOR_BGR2GRAY)
aruco_dict = cv.aruco.getPredefinedDictionary(cv.aruco.DICT_ARUCO_ORIGINAL)
parameters = cv.aruco.DetectorParameters()
detector = cv.aruco.ArucoDetector(aruco_dict, parameters)
corners, ids, _ = detector.detectMarkers(gray)
if ids is None:
    print("No markers detected.")
else:
    print("Detected markers:", ids.flatten())
    marker_positions = {
        int(ids[i][0]): [int(np.mean([pt[1] for pt in corners[i][0]])), int(np.mean([pt[0] for pt in corners[i][0]]))]
        for i in range(len(ids))
    }
    marker_positions = dict(sorted(marker_positions.items()))
    print("Marker positions:", marker_positions)
    import numpy as np
def determine_turn(prev_direction, next_direction):
    cross_product = prev_direction[0] * next_direction[1] - prev_direction[1] * next_direction[0]
    if cross_product > 0:
        return 'L' 
    elif cross_product < 0:
        return 'R' 
    else:
        return 'F'  
pathL = ['S']  
directions = []
keys = list(marker_positions.keys())
for i in range(len(keys) - 1):
    delta = np.array(marker_positions[keys[i + 1]]) - np.array(marker_positions[keys[i]])
    directions.append([np.sign(delta[0]), np.sign(delta[1])])
for j in range(len(directions) - 1):
    turn = determine_turn(directions[j], directions[j + 1])
    pathL.append(turn)

pathL.append('E')  
print("Path:", pathL)




