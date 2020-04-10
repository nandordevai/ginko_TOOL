# Ginko Synthese TOOL

Repository of firmwares for the [Ginko Synthese](http://www.ginkosynthese.com/) TOOL module.
Includes the module specific Arduino library, encapsulating some common functionalities.

## Contributors:
Original design: [Jan Willem](http://www.ginkosynthese.com/)

TOOL library/Firmwares:
[Vladimir Riznic](https://github.com/dgmt)

Additional firmware: [Nandor Devai](https://github.com/nandordevai)

## Installation

Clone the repository, and copy the TOOLlib folder into your Arduino `libraries` folder.

Copy other folders into your `Sketches` folder.

Burn into your TOOL module as you would any other Arduino sketch.

## Firmwares

### CV based

* CV Offset
* Random & Hold with random generator range selection
* Sample & Hold
* Random looping CV

### Gate/Trigger based

* Probabilistic Clock Divider

### Audio based

* Simplest Bitcrush
* Buffer Freeze (has problems for now, needs solving)
