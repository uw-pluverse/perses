trait X[R <: Z, Z >: X[R, R]]
class Z extends X[Z, Z]
