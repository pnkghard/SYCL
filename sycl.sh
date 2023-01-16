#!/bin/bash
#!/bin/bash
#SBATCH --gres=gpu:1
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --mail-type=ALL
#SBATCH --time=00:30:00
#SBATCH --job-name=a.out
#SBATCH --output=output%j.out
#SBATCH --error=error%j.err
source /opt/intel/oneapi/setvars.sh > /dev/null 2>&1
./a.out