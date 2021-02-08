why do you need `docker run --init`?

[PID 1](https://engineeringblog.yelp.com/2016/01/dumb-init-an-init-for-docker.html#process-behavior-inside-docker-containers)

[signal handler register](https://github.com/moby/moby/issues/2838#issuecomment-194054757)
![](./signal%20handler.png)


run a container with no options and by default you have a stdout stream (so docker run <cmd> works); 
run with `-i`, and you get stdin stream added (so <cmd> | docker run -i works); 
```bash
$ echo 'echo abc' | docker run -i alpine 
$ abc
$ echo 'echo abc' | docker run  alpine 
  (nothing)
```
use `-t`, you have a sudo-tty attached. You are able to send `SIGINT` to process
see [this example](https://github.com/moby/moby/issues/2838#issuecomment-194708691)