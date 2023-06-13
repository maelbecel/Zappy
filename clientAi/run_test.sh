./zappy_server -p 4242 -x 20 -y 20 -n team1 team2 -c 5 -f 40 &
pytest ./tests/ai/*.py
kill %1
