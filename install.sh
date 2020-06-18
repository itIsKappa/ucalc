echo "Initializing installation..."
sleep 1
echo "Moving ucalc to /usr/bin"
mv ucalc /usr/bin
sleep 1
echo "[ OK ]"
echo "Creating ucalc directory in /usr/share"
mkdir /usr/share/ucalc
sleep 1
echo "[ OK ]"
echo "Moving ucalcLog.txt to /usr/share/ucalc/"
mv ucalcLog.txt /usr/share/ucalc/
sleep 1
echo "[ OK ]"
echo "Creating copyright at /usr/share/doc/ucalc/"
mkdir /usr/share/doc/ucalc
mv COPYING /usr/share/doc/ucalc/
sleep 1
echo "[ OK ]"
echo "###################### D O N E ######################"

