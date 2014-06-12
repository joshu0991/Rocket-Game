import pygame
import sys
from pygame.locals import*
pygame.init()
pygame.key.set_repeat(30, 30)

#leftTriPoints = [(60, 40), (60, 80), (90, 80)]
white = (255, 255, 255)
black = (0, 0, 0)
bg = pygame.image.load('backDrop.png')
rocketImg =pygame.image.load('Rocket.png')

score = 0
fps = 50
displayWidth = 800
displayHeight = 600
speed = 250


UP = 'up'
DOWN = 'down'
RIGHT = 'right'
LEFT = 'left'

def runGame():
    x, y = 1, 1
    movX, movY = 0, 0
    while True: 
        msgSuface('Score: '+ str(score), white)
        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == KEYDOWN:
                if event.key == (K_UP):
                    movY = -1
                elif event.key == (K_DOWN):
                    movY = 1
                elif event.key == (K_RIGHT):
                    movX = 1
                elif event.key == (K_LEFT):
                    movX = -1
            if event.type == KEYUP:
                if event.key == (K_UP):
                    movY = 0
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
        x +=(movX * dm)
        y+= (movY * dm)  
        screen.blit(bg, (0,0))
        screen.blit(rocketImg, (x, y))
        pygame.display.update()
        
def msgSuface(text, color):
    smallText = pygame.font.Font('freesansbold.ttf', 20)
    #largeText = pygame.font.Font('freesansbold.ttf', 150)
    titleTextSurf, titleTextRect = makeTextObjs(text, smallText, color)
    titleTextRect.center = (500, 30)
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
#Stopped on video 11 https://www.youtube.com/watch?v=eAkOlzNXu_o&index=11&list=PLQVvvaa0QuDcxG_Cajz1JyTH6eAvka93C