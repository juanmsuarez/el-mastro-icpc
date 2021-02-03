// Invariante: a cumple, b no cumple
// Si no se conoce un valor que cumpla, a puede ser un valor imaginario, como -1.
// Requisito: si b no cumple, b+1 tampoco ("propiedad binaria")
a = unChabonQueCumple;
b = unChabonQueNoCumple;
while (b - a > 1)
{
    c = (a+b)/2;
    if (c cumple)
        a = c;
    else
        b = c;
}
// a tiene el ultimo que cumple
// b tiene el primero que no cumple
