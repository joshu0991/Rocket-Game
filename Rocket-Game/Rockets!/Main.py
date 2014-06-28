import pygame
import sys
from threading import *
from pygame.locals import*
import Missle, Rocket
pygame.init()
pygame.key.set_repeat(30, 30)

white = (255, 255, 255)
black = (0, 0, 0)
bg = pygame.image.load('backDrop.png')

score = 0000000
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
rocket = Rocket.Rocket()

def runGame():
    global missleMap
    speedUp = False
    movX, movY = 0, 0
    s = "Score " + str(score)
    while True:
        playSound("Idle.wav") 
        key = pygame.key.get_pressed()
        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                sys.exit()
                
            elif event.type == KEYDOWN:
                if key[pygame.K_SPACE]: speedUp = True
                if key[pygame.K_UP]:
                    if speedUp == True:
                        movY = -4
                    else:
                        movY = -2
                if key[pygame.K_DOWN]:
                    if speedUp == True:
                        movY = 4
                    else:
                        movY = 2
                if key[pygame.K_RIGHT]:
                    if speedUp == True:
                        movX = 4
                    else:
                        movX = 2
                if key[pygame.K_LEFT]:
                    if speedUp == True:
                        movX = -4
                    else:
                        movX = -2
                if key[pygame.K_q]: makeMissle('l')
                if key[pygame.K_w]: makeMissle('r')
                    
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
        if rocket.x >displayWidth - 130:
            movX = 0
            rocket.x = displayWidth - 132
        elif rocket.x < 1:
            movX = 0
            rocket.x = 2
        elif rocket.y < 1:
            movY = 0
            rocket.y = 2
        elif rocket.y > displayHeight - 165:
            movY = 0
            rocket.y = displayHeight - 167
        milli = fpsTime.tick()
        sec = milli/1000.0
        dm = sec * speed
        rocket.move(dm, movX, movY)
        screen.blit(bg, (0,0))
        for m in missleMap:
            m.fire()
            screen.blit(m.missileImg, (m.misX, m.misY))
        msgSuface(s, white)
        screen.blit(rocket.rocketImg, (rocket.x, rocket.y))
        pygame.display.update()
        destroyMissles()
        
        
def makeMissle(side):
    global x, y, tracker
    missleMap.insert(tracker, Missle.Missle(rocket.x, rocket.y, 16, side))
    tracker+=1
    
def destroyMissles():
    global missleMap, tracker
    for m in missleMap:
        if m.misY <= 0:
            missleMap.remove(m)
        if tracker >= 75:
            tracker = 0

def msgSuface(text, color):
    smallText = pygame.font.Font('freesansbold.ttf', 20)
    titleTextSurf, titleTextRect = makeTextObjs(text, smallText, color)
    titleTextRect.center = (720, 30)
    screen.blit(titleTextSurf, titleTextRect)

def makeTextObjs(text, font, color):
    textSurface = font.render(text, True, color)
    return textSurface, textSurface.get_rect()

def playSound(fileName):
    s = pygame.mixer.Sound(fileName)
    s.play()
    
while True:
        global fpsTime
        global screen
        playSound('ShipTwo.wav')
        fpsTime = pygame.time.Clock()
        screen = pygame.display.set_mode((displayWidth, displayHeight))
        pygame.display.set_caption('Rockets!')
        runGame()
#Fix shooting!!!!!
#Resource for enemy http://stackoverflow.com/questions/16945498/how-can-i-have-multiple-objects-moving-at-once-in-pygame
#Stopped on video 11 https://www.youtube.com/watch?v=eAkOlzNXu_o&indeqx=11&list=PLQVvvaa0QuDcxG_Cajz1JyTH6eAvka93C