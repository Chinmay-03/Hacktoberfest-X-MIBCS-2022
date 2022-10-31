"""
Demonstration of the GazeTracking library.
Check the README.md for complete documentation.
"""

import cv2
from gaze_tracking import GazeTracking

gaze = GazeTracking()
webcam = cv2.VideoCapture(1)

def cam1():
    cap=cv2.VideoCapture(0)
    if (cap.isOpened()==False):
        print("Unable to read camera feed")
    fw=int(cap.get(3))
    fh=int(cap.get(4))
    i=0
    ret,frame=cap.read()
    if ret == True:
        cv2.flip(frame,180) #flipping frame by 180
        cv2.imshow('frame',frame)

        if cv2.waitKey(1) & 0xFF==ord('q'):
            exit()

    else:
        exit()

def cam2():
    cap=cv2.VideoCapture(2)
    if (cap.isOpened()==False):
        print("Unable to read camera feed")
    fw=int(cap.get(3))
    fh=int(cap.get(4))
    i=0
    ret,frame=cap.read()
    if ret == True:
        cv2.flip(frame,180) #flipping frame by 180
        cv2.imshow('frame',frame)

        if cv2.waitKey(1) & 0xFF==ord('q'):
            exit()

    else:
        exit()

while True:
    # We get a new frame from the webcam
    _, frame = webcam.read()
    # We send this frame to GazeTracking to analyze it
    gaze.refresh(frame)

    frame = gaze.annotated_frame()
    text = ""
    left_pupil = gaze.pupil_left_coords()
    right_pupil = gaze.pupil_right_coords()
    
    if gaze.is_section1():
        text = gaze.is_section1()
        
    elif gaze.is_section2():
        text = gaze.is_section2()
        
    elif gaze.is_section3():
        text = gaze.is_section3()

    elif gaze.is_blinking():
        text = "Blinking"
        
    print("Section ",text,"                 ",left_pupil,"       ",right_pupil)
    print()
    if text==1 or text == 2:
        cam1()
    elif text==3:
        cam2()
    

    #cv2.putText(frame, text, (90, 60), cv2.FONT_HERSHEY_DUPLEX, 1.6, (147, 58, 31), 2)

    left_pupil = gaze.pupil_left_coords()
    right_pupil = gaze.pupil_right_coords()
    #cv2.putText(frame, "Left pupil:  " + str(left_pupil), (90, 130), cv2.FONT_HERSHEY_DUPLEX, 0.9, (147, 58, 31), 1)
    #cv2.putText(frame, "Right pupil: " + str(right_pupil), (90, 165), cv2.FONT_HERSHEY_DUPLEX, 0.9, (147, 58, 31), 1)

    cv2.imshow("Demo", frame)

    if cv2.waitKey(1) == 27:
        break
   
webcam.release()
cv2.destroyAllWindows()