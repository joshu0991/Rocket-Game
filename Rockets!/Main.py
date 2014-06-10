import pygame
import sys
from pygame.locals import*
pygame.init()
pygame.key.set_repeat(30, 30)

white = (255, 255, 255)
black = (0, 0, 0)
bg = black


fps = 50
displayWidth = 800
displayHeight = 600
cellSize = 10

UP = 'up'
DOWN = 'down'
RIGHT = 'right'
LEFT = 'left'

def runGame():
    startx = 3
    starty = 3
    coords = [{'x':startx, 'y':starty}]
    direction = RIGHT
    isBound = True
    while True:
        
        while isBound == True:
        
            for event in pygame.event.get():
                if event.type == QUIT:
                    pygame.quit()
                    sys.exit()
                elif event.type == KEYDOWN:
                    if event.key == (K_UP):
                        direction = UP
                    elif event.key == (K_DOWN):
                        direction = DOWN
                    elif event.key == (K_RIGHT):
                        direction = RIGHT
                    elif event.key == (K_LEFT):
                        direction = LEFT
                if direction == UP:
                    newCell = {'x':coords[0]['x'], 'y':coords[0]['y']-1}
                elif direction == DOWN:
                    newCell = {'x':coords[0]['x'], 'y':coords[0]['y']+1}
                elif direction == RIGHT:
                    newCell = {'x':coords[0]['x']+1, 'y':coords[0]['y']}
                elif direction == LEFT:
                    newCell = {'x':coords[0]['x']-1, 'y':coords[0]['y']}
                del coords[-1]
                coords.insert(0, newCell)
                setDisplay.fill(bg)
                drawCell(coords)
                pygame.display.update()
                fpsTime.tick(fps)
            
def drawCell(coords):
    for coord in coords:
        x = coord['x']*cellSize
        y = coord['y']*cellSize
        makeCell = pygame.Rect(x, y, cellSize, cellSize)
        pygame.draw.rect(setDisplay, white, makeCell)
while True:
        global fpsTime
        global setDisplay
        fpsTime = pygame.time.Clock()
        setDisplay = pygame.display.set_mode((displayWidth, displayHeight))
        pygame.display.set_caption('Rockets!')
        runGame()


#Stopped on video 11 https://www.youtube.com/watch?v=eAkOlzNXu_o&index=11&list=PLQVvvaa0QuDcxG_Cajz1JyTH6eAvka93C