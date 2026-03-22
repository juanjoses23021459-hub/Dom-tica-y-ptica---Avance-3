package main

import (
	"fmt"
	"time"
)

// Constantes de configuración para el sistema óptico
const (
	UmbralLuz  = 450
	Histeresis = 60
)

// Estructura para el controlador de iluminación
type ControladorDomotico struct {
	LucesEncendidas bool
	Historial       []int
}

func (c *ControladorDomotico) AnalizarLectura(lectura int) {
	// Guardar en historial (limitado a las últimas 10 lecturas)
	if len(c.Historial) >= 10 {
		c.Historial = c.Historial[1:]
	}
	c.Historial = append(c.Historial, lectura)

	// Lógica de control con histéresis
	if lectura < (UmbralLuz-Histeresis) && !c.LucesEncendidas {
		c.CambiarEstado(true)
	} else if lectura > (UmbralLuz+Histeresis) && c.LucesEncendidas {
		c.CambiarEstado(false)
	}

	c.MostrarStatus(lectura)
}

func (c *ControladorDomotico) CambiarEstado(nuevoEstado bool) {
	c.LucesEncendidas = nuevoEstado
	accion := "APAGANDO"
	if nuevoEstado {
		accion = "ENCENDIENDO"
	}
	fmt.Printf("\n[SISTEMA GO] >> Acción: %s luces del área...\n", accion)
}

func (c *ControladorDomotico) MostrarStatus(actual int) {
	estadoStr := "🌑 [OFF]"
	if c.LucesEncendidas {
		estadoStr = "💡 [ON]"
	}
	fmt.Printf("Lectura Sensor: %4d | Estado Actual: %s\n", actual, estadoStr)
}

func main() {
	fmt.Println("--- Monitor de Sensores Ópticos (Golang) ---")
	
	sistema := &ControladorDomotico{LucesEncendidas: false}
  
