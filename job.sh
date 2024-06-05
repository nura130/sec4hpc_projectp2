#!/bin/bash

#SBATCH --job-name=matrix_multiplication
#SBATCH --output=output.txt
#SBATCH --error=error.txt
#SBATCH --ntasks=2  # Adjust the number of tasks as needed
#SBATCH --time=02:00  # Set a reasonable time limit
#SBATCH --partition=g100_all_serial  # Specify the partition, adjust if necessary

#Load Singularity
module load singularity

# Define paths to input matrices
MATRIX_A="matrixA.txt"
MATRIX_B="matrixB.txt"

# Define path to Singularity container
CONTAINER_IMAGE="matrix_multiplication.sif"

# Run the compiled executable inside the Singularity container
singularity exec $CONTAINER_IMAGE mpirun -np 2 ./matrix_multiplication $MATRIX_A $MATRIX_B
