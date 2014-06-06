import pygame, sys, Rocket, Utility
from pygame.locals import *
pygame.init()

UP = 'up'
DOWN = 'down'
RIGHT = 'right'
LEFT = 'left'
fps = 150
cellsize = 10
def runGame():
    startx = 3
    starty = 3
    coords = [{'x':startx, 'y':starty}]
    while True:
        for event in pygame.event.get():
            if(event.type == pygame.QUIT):
                sys.exit()
            # stopped on video 8 https://www.youtube.com/watch?v=VNLLeBVLEoo&index=8&list=PLQVvvaa0QuDcxG_Cajz1JyTH6eAvka93C

size = WIDTH, HEIGHT = 900, 650
pygame.display.init()
screen = pygame.display.set_mode(size)
pygame.display.set_caption('Rocketships!')
running = True
sound = pygame.mixer.Sound('UFO_Takeoff.wav')
sound.play()
x = 0 
y = 0
pixmove = 3
black = 0,0,0
movement = 'down'
rocket = Rocket.Rocket(screen)
#rocketTwo = Rocket.Rocket(screen)
util = Utility.Utility()
fpsTime = pygame.time.Clock()
while running:
    if movement == 'down':
        y += pixmove
        if y > 400:
            movement = 'right'
    elif movement == 'right':
        x += pixmove
        if x > 700:
            movement = 'up'
    elif movement == 'up':
        y -= pixmove
        if y < 10:
            movement = 'left'
    elif movement == 'left':
        x -= pixmove
        if x < 10:
            movement = 'down'
    screen.fill(black)    
    rocket.move(x, y, size)
    #rocket.move(10, 10)
    pygame.display.update()
    fpsTime.tick(fps)
    for event in pygame.event.get():
        if(event.type == pygame.QUIT):
            running = False