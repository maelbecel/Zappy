#!/bin/bash

echo "Running functional tests..."

cd ../../
./zappy_server -f 10 -p 4242 & echo $! > server.pid

cd tests/functionals

cd ../../
kill -9 $(cat server.pid)
rm server.pid

echo "Done."