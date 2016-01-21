// Задача на сигналы.

// Создайте процесс (сохраните его PID в /home/box/pid), устойчивый к сигналам SIGTERM и SIGINT (неубиваемый).

#!/bin/bash
trap "" SIGTERM SIGINT
exec "$@"

bash nosig.sh sleep 60