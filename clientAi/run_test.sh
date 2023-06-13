./zappy_server -p 4242 -x 20 -y 20 -n team1 team2 -c 5 -f 40 &
pid=$!
echo $pid
pytest ./tests/ai/*.py
kill $pid
