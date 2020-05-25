echo "Initializing installation..."
echo "Moving ucalc to /usr/bin"
mv ucalc /usr/bin
echo "[ OK ]"
echo "Creating ucalc directory in /usr/share"
mkdir /usr/share/ucalc
echo "[ OK ]"
echo "Moving ucalcLog.txt to /usr/share/ucalc/"
mv ucalcLog.txt /usr/share/ucalc/
echo "[ OK ]"
echo "Creating copyright at /usr/share/doc/ucalc/"
mkdir /usr/share/doc/ucalc
mv COPYING /usr/share/doc/ucalc/
echo "[ OK ]"
echo "###################### D O N E ######################"

