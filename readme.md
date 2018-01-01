# urg_test
ROSでURGを使う際のサンプルコード.  
1秒ごとにURGの取得データのうち中央の距離/強度データを出力します.  
実際に使うURGに合わせて `launch/urg_test.launch` を変更してください.  
起動は `catkin_make` した後に
```
roslaunch urg_test urg_test.launch
```
