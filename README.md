# MCMS (Manhole Cover Monitoring System)

## Problem Statement
Theft of manhole covers is a severe problem faced by our nation that has been left unaddressed for a long time.The repercussions of this thievery not only amount to material losses but also lead to loss of lives. This project proposes a solution to this problem by building a manhole cover monitoring system. Given that a sensor placed inside the manhole will not have reliable connection to the internet, we can directly send the sensor details using internet. This system will give the real-time status of the covers using a LoRa-based gateway to send the data to a cloud server keeping the authorities informed.

## Introduction and Motivation
Theft of manhole covers leads to accidents and deaths. At
first, this might seem like a very unlikely problem, but in
2004 Calcutta witnessed the theft of more than 10000
manhole covers over a period of two months. Thieves
steal these covers to sell them as scrap iron, the profit
made out of these acts is not much but the loss incurred
by society is much greater.
This type of theft is performed at locations experiencing
less traffic and spots which are not monitored with CCTV
cameras. These uncovered holes pose serious danger to
vehicles, especially two-wheelers which end in fatal crashes.
The pedestrians might be able to spot a big hole in daylight
but at night in darkness the chances of any mishappening
increase manifold.
Thus it becomes imperative to come up with a solution
to curb these acts of petty thievery leading to unfortunate
fatalities.

## Proposed Solution
<img src="">
The suggested model is represented in three sections:

1. **LoRa end-devices:** The end devices are composed of sensors capable of
monitoring the status of the cover on the manhole.
The microcontroller reading this sensor is integrated
with a LoRa transmitter.
1. **Integrating internet connectivity:** Signals from the nodes of a given region would be
received by a common LoRa-based gateway connected
to an internet access point.
1. **Cloud server and web interface:** Using the connectivity provided by the gateway, the
data is uploaded to a cloud-based server and displayed
on a web interface or sent to the municipal authorities.

## Block Diagram System representation

 
