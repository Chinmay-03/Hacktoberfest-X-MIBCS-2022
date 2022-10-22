import cv2
# import cv2 for image reading, changing colors & finding the brightest point

image = cv2.imread('star.jpg')
image1 =cv2.resize(image,(600,800))
cv2.imshow('image_rgb',image1)
cv2.waitKey(0)

gray = cv2.cvtColor(image1, cv2.COLOR_BGR2GRAY)
cv2.minMaxLoc(gray)
cv2.imshow('gray image', gray)
cv2.waitKey(0)
#print(cv2.minMaxLoc(gray))
# (6.0, 248.0, (599, 13), (315, 461))
x_coordinate=cv2.minMaxLoc(gray)[3][2]
y_coordinate=cv2.minMaxLoc(gray)[3][1]
print("The Coordinates of the brightest point are " ,x_coordinate,y_coordinate)

# To plot the rectangle around the brightest point
s=20
coordinate1=(x_coordinate-s,y_coordinate+s)
coordinate2=(x_coordinate-s,y_coordinate-s)
color=((50,205,50))
t=5
# To show the location of the brightest point on the image
brightest=image1
brightest=cv2.rectangle(brightest,coordinate1,coordinate2,color,t)
cv2.putText(brightest,"  (315,461)",(315,461),cv2.FONT_HERSHEY_SIMPLEX,1,(240,248,255),2)
cv2.imshow('Bright Star',brightest)
cv2.waitKey(0)

# Output
# The Coordinates of the brightest point are : (315,461)