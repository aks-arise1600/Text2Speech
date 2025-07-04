# Text2Speech
Text2Speech is an Qt based UI application that converts written text into spoken voice output. It enables machines to read out text aloud using synthesized human-like voices.


## Dependencies install

		sudo apt update
		sudo apt install speech-dispatcher espeak-ng
		sudo apt install libqt5texttospeech5 libqt5texttospeech5-dev


## Qmake build

		git clone https://github.com/aks-arise1600/Text2Speech.git
		mkdir qbuild && cd qbuild
		qmake ..
		make
		
## Cmake build

		git clone https://github.com/aks-arise1600/Text2Speech.git
		mkdir cbuild && cd cbuild
		cmake ..
		make
