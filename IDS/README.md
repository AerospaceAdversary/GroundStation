# NewtorkIDS
A series of machine-learning based implementations of an Intrustion Detection System for network traffic. Current completed implementations are:
- Random Forest
- Naive Bayes

The goal of the models is to classify network traffic features into 5 categories:
1. Normal traffic
2. DOS Attack
3. Probe Attack
4. Priviledge Attack
5. Access Attack

# Setup
Install dependencies
```
sudo apt update
apt install git python3-dev python3-pip build-essential libagg-dev pkg-config
```
Install requirements
```
python3 -m venv env
. env/bin/activate
pip3 install -r requirements.txt
```
Lastly, for benchmarking, [download the NSL-KDD dataset](https://www.unb.ca/cic/datasets/nsl.html) and extract the dataset into the project directory.

# Program execution
The program can be run in two modes **train** and **predict**. In train, we feed the model labeled instances of a dataset, and optimize the models parameters to best classify the input network traffic. Once the model is trained, we can run the model in predict mode, where we feed the model network traffic data and the model returns a classification of the traffic. 

## Train
To run the program in train mode from the project directory, run:
```
python3 main_ids.py --mode train --model model --train-data train-directory --model-file model-name
```
Where **model** is replaced with the model you would like to train from the list specified above, **train-directory** is replaced with a path to the train set and **model-file** is replaced with the name you would like to save the model as.

For example:
```
python3 main_ids.py --mode train --model random-forest --train-data ./NSL-KDD/KDDTrain+.txt --model-file random-forest-model
```

## Predict
To run the program in predict mode from the project directory (requires a pretrained model), run:
```
python3 main_ids.py --mode predict --predict-data predict-directory --model-file model-name 
```

Where **predict-directory** is replaced with a path to the network traffic you would like to predict and **model-name** is replaced with the name of the pretrained model.

For example:
```
python3 main_ids.py --mode predict --predict-data predict.txt
```
