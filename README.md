To build the image and set up the container, run `docker-compose up -d`

Access the conteiner with `docker exec -it lpg-ubuntu-gcc bash`

To test, run `gcc hello.c -o main` and `./main`