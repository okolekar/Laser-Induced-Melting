"""
Topic:   Programming of the 2D FE Implementation of Stefan Problem and the Enthalpy Problem.
Program: The Enthalpy Problem               Matriculation Number: 66808
"""
# Amorphous_Material_Constants
# Default Material: - SS304L

soliduspt   = 1670               #Solidus Point                             # Kelvin
liquidouspt = 1727               #Liqudus Point                             # Kelvin
vapourpt    = 3375               #Vapour Point                              # Kelvin
Iref        = 1.5*10**10         #Reference Intensity                       # W/m^2
I           = 2.5*10**10         #Used Intensity                            # W/m^2
k           = 22                 #Conductivity                              # W/m-K 
delt        = 0.001              #time step size                                    
n           = 301                #number of nodes                           
c           = 700                #specific heat capacity                    # in J/kg/K
rho         = 7200               #density of the material                   # kg/m**3  
Lf          = 0.000000001*261000 #latent  heat of fusion                    # J/kg   
depth       = 1                  #total depth to be simulated               # meters  
t_end       = 300                #End time for simulation                   # dimensionless