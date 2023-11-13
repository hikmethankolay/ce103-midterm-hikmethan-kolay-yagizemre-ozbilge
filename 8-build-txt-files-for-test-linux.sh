echo "0-)TEXT STRING0" > test1.txt
echo "1-)TEXT STRING1" >> test1.txt
echo "2-)TEXT STRING2" >> test1.txt
echo "3-)TEXT STRING3" >> test1.txt
echo "4-)TEXT STRING4" >> test1.txt

echo "0-)TEXT STRING0" > test2.txt
echo "1-)TEXT STRING1" >> test2.txt
echo "2-)TEXT STRING2" >> test2.txt
echo "3-)TEXT STRING3" >> test2.txt
echo "4-)TEXT STRING4" >> test2.txt

echo "0-)TEXT STRING0" > test3.txt
echo "1-)TEXT STRING1" >> test3.txt
echo "2-)TEXT STRING2" >> test3.txt
echo "3-)TEXT STRING3" >> test3.txt
echo "4-)TEXT STRING4" >> test3.txt

echo "0-)TEXT STRING0" > test4.txt
echo "1-)TEXT STRING1" >> test4.txt
echo "2-)TEXT STRING2" >> test4.txt
echo "3-)TEXT STRING3" >> test4.txt
echo "4-)TEXT STRING4" >> test4.txt

echo "0-)TEXT STRING0" > test5.txt
echo "1-)TEXT STRING1" >> test5.txt
echo "2-)TEXT STRING2" >> test5.txt
echo "3-)TEXT STRING3" >> test5.txt
echo "4-)TEXT STRING4" >> test5.txt

cp test1.txt build_linux/src/tests/farm_management
cp test2.txt build_linux/src/tests/farm_management
cp test3.txt build_linux/src/tests/farm_management
cp test4.txt build_linux/src/tests/farm_management
cp test5.txt build_linux/src/tests/farm_management

cp test1.txt publish_linux/bin
cp test2.txt publish_linux/bin
cp test3.txt publish_linux/bin
cp test4.txt publish_linux/bin
cp test5.txt publish_linux/bin

echo "txt files created successfully"
