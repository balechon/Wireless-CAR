#codigo 100% real no feik de bryan lechon
import socket
import sys
import pygame
import time

serverAddressPort   = ("192.168.0.157", 1337)
msga = "a"
msgw = "w"
msgs = "s"
msgq = "q"   
msgd = "d"
msge = "e"
msgp = "p"
# inicializa Pygame

#Create a UDP socket at client side

UDPClientSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)

print("conectado")

pygame.init()

#dimesiones de la ventana
dimensiones = [400, 400]
pantalla = pygame.display.set_mode(dimensiones)
#titulo de la ventana
pygame.display.set_caption("Inalambricas Proyecto")
reloj = pygame.time.Clock()

# Inicializa los joysticks
joystick = pygame.joystick.Joystick(0)
joystick.init()
print ("Detected joystick '",joystick.get_name(),"'")


# bucle infinito
while True:
    time.sleep(0.23)
    for event in pygame.event.get():
        # si se presiona el botón 'cerrar' de la ventana
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    #leer botones    
    A=joystick.get_button(0)
    B=joystick.get_button(1)
    X=joystick.get_button(2)
    
    LB=joystick.get_button(4)
    RB=joystick.get_button(5)
    hat = joystick.get_hat(0)
    #adelante
    if A==1 and RB==0 and LB==0:
        print("adelante")
        UDPClientSocket.sendto(str.encode(msgw), serverAddressPort)
    #adelante derecha    
    if A==0 and RB==1 and LB==0:
        print("adeDerecha")
        UDPClientSocket.sendto(str.encode(msge), serverAddressPort)            
    if A==1 and RB==1:
        print("adeDerecha")
        UDPClientSocket.sendto(str.encode(msge), serverAddressPort)
    #adelante izquierda
    if A==0 and RB==0 and LB==1 :
        print("adeIzquierda")
        UDPClientSocket.sendto(str.encode(msgq), serverAddressPort)        
    if A==1 and LB==1:
        print("adeIzquierda")
        UDPClientSocket.sendto(str.encode(msgq), serverAddressPort)
    #atras        
    if hat==(0, -1) and X==0:
        print("atras")
        UDPClientSocket.sendto(str.encode(msgs), serverAddressPort)
    #atras derecha
    if hat==(1, -0) and X==0:
        print("RevDerecha")
        UDPClientSocket.sendto(str.encode(msgd), serverAddressPort)
    #atras izuierda
    if hat==(-1, 0) and X==0:
        print("RevIzquierda")
        UDPClientSocket.sendto(str.encode(msga), serverAddressPort)
    #parar
    if B==1 and A==0:
        print("Parar")
        UDPClientSocket.sendto(str.encode(msgp), serverAddressPort)
pygame.quit()




