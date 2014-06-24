import pygame
import sys
from threading import *
from pygame.locals import*
import Missle
pygame.init()
pygame.key.set_repeat(30, 30)

white = (255, 255, 255)
black = (0, 0, 0)
bg = pygame.image.load('backDrop.png')
rocketImg =pygame.image.load('Rocket.png')

score = 5000000
fps = 50
displayWidth = 800
displayHeight = 600
speed = 250


UP = 'up'
DOWN = 'down'
RIGHT = 'right'
LEFT = 'left'

missleMap = []
tracker = 0

def runGame():
    global missleMap
    global tracker
    speedUp = False
    x, y = 1, 1
    movX, movY = 0, 0
    s = "Score " + str(score)
    while True: 
        msgSuface(s, white)
        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == KEYDOWN:
                if event.key == (K_SPACE):
                    speedUp = True
                if event.key == (K_UP):
                    if speedUp == True:
                        movY = -3
                    else:
                        movY = -1
                elif event.key == (K_DOWN):
                    if speedUp == True:
                        movY = 3
                    else:
                        movY = 1
                elif event.key == (K_RIGHT):
                    if speedUp == True:
                        movX = 3
                    else:
                        movX = 1
                elif event.key == (K_LEFT):
                    if speedUp == True:
                        movX = -3
                    else:
                        movX = -1
                elif event.key == (K_q):
                    missleMap.insert(tracker, Missle.Missle(x, y, 2))
                    tracker+=1
            if event.type == KEYUP:
                if event.key == (K_UP):
                    movY = 0
                elif event.key == (K_SPACE):
                    speedUp = False
                elif event.key == (K_DOWN):
                    movY = 0
                elif event.key == (K_RIGHT):
                    movX = 0
                elif event.key == (K_LEFT):
                    movY = 0
        if x >displayWidth - 130:
            movX = 0
            x = displayWidth - 132
        elif x < 1:
            movX = 0
            x = 2
        elif y < 1:
            movY = 0
            y = 2
        elif y > displayHeight - 165:
            movY = 0
            y = displayHeight - 167
        milli = fpsTime.tick()
        sec = milli/1000.0
        dm = sec * speed
        x += (movX * dm)
        y += (movY * dm)
        for m in missleMap:
            m.fireGunOne()
            screen.blit(m.missileImg, (m.misX, m.misY))
        screen.blit(bg, (0,0))
        screen.blit(rocketImg, (x, y))
        pygame.display.update()
        
def msgSuface(text, color):
    smallText = pygame.font.Font('freesansbold.ttf', 20)
    #largeText = pygame.font.Font('freesansbold.ttf', 150)
    titleTextSurf, titleTextRect = makeTextObjs(text, smallText, color)
    titleTextRect.center = (720, 30)
    screen.blit(titleTextSurf, titleTextRect)

def makeTextObjs(text, font, color):
    textSurface = font.render(text, True, color)
    return textSurface, textSurface.get_rect()

while True:
        global fpsTime
        global screen
        fpsTime = pygame.time.Clock()
        screen = pygame.display.set_mode((displayWidth, displayHeight))
        pygame.display.set_caption('Rockets!')
        runGame()
#Fix shooting!!!!!
#Resource for enemy http://stackoverflow.com/questions/16945498/how-can-i-have-multiple-objects-moving-at-once-in-pygame
#Stopped on video 11 https://www.youtube.com/watch?v=eAkOlzNXu_o&indeqx=11&list=PLQVvvaa0QuDcxG_Cajz1JyTH6eAvka93C