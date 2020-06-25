### compute math PI
# draw a circle inside a square
# the area of circle over square is pi/4
## area of circle = pi * r^2
## area of square = (2r) * (2r)
## so Area_circle/Area_square = pi/4
## assume you throw dot into the square, the probablity of dot inside the circle is pi/4

##
r = 1 # circle radius = 1
n = 100000
x = runif(n, min=0, max = 2)
y = runif(n, min=0, max = 2)

distf <- function(x,y){
  ## measure the distance to (r,r) # the center of circle
  dis = sqrt((x-1)^2  + (y-1)^2 )
  return(dis)
}

alldist = c()
for(i in 1:length(x)){
  di = distf(x[i],y[i])
  alldist <- c(alldist,di)
}

# 
n_incirlce = length(alldist[alldist<=1])
pi = n_incirlce/length(alldist) * 4
pi
