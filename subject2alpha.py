from google.colab import drive
drive.mount('/content/drive')

# 1. Install Detectron2
!pip install -U torch torchvision
!pip install git+https://github.com/facebookresearch/detectron2.git

# 2. Import necessary libraries
import os
import cv2
import numpy as np
import torch
import detectron2.data.transforms as T
from detectron2 import model_zoo
from detectron2.utils.logger import setup_logger
from detectron2.engine import DefaultPredictor
from detectron2.config import get_cfg
from detectron2.data import MetadataCatalog
from google.colab.patches import cv2_imshow
from PIL import Image

setup_logger()

# 3. Load a pre-trained instance segmentation model from Detectron2
cfg = get_cfg()
cfg.merge_from_file(model_zoo.get_config_file("COCO-InstanceSegmentation/mask_rcnn_R_50_FPN_3x.yaml"))
cfg.MODEL.ROI_HEADS.SCORE_THRESH_TEST = 0.5  # Set the confidence threshold
cfg.MODEL.WEIGHTS = model_zoo.get_checkpoint_url("COCO-InstanceSegmentation/mask_rcnn_R_50_FPN_3x.yaml")
predictor = DefaultPredictor(cfg)

# 4. Define the subject of interest based on user input
subject_of_interest = input("Enter the subject of interest (e.g., 'a woman'): ").lower()
subject_class_id = None
if "woman" in subject_of_interest or "person" in subject_of_interest:
    subject_class_id = MetadataCatalog.get(cfg.DATASETS.TRAIN[0]).thing_classes.index("person")

# 5. Define input and output directories
input_directory = "/content/drive/MyDrive/name/of/your/input/image/folder"
output_directory = "/content/drive/MyDrive/name/of/your/output/image/folder"

# Create the output directory if it doesn't exist
os.makedirs(output_directory, exist_ok=True)

# 6. Iterate over all the PNG images in the input directory
for file_name in os.listdir(input_directory):
    if file_name.lower().endswith(".png"):
        input_image_path = os.path.join(input_directory, file_name)
        img = cv2.imread(input_image_path)

        # 7. Make predictions and get instance segmentation masks
        outputs = predictor(img)

        # 8. Find the subject of interest
        if subject_class_id is not None:
            subject_instances = [i for i, cls in enumerate(outputs["instances"].pred_classes) if cls == subject_class_id]

        # 9. Create an alpha channel mask
        alpha = np.zeros(img.shape[:2], dtype=np.uint8)
        for instance_id in subject_instances:
            mask = outputs["instances"].pred_masks[instance_id].cpu().numpy().astype(np.uint8) * 255
            alpha = cv2.add(alpha, mask)

        # 10. Add the alpha channel to the input image
        img_with_alpha = cv2.cvtColor(img, cv2.COLOR_BGR2BGRA)
        img_with_alpha[:, :, 3] = alpha

        # 11. Save the image with the alpha channel
        output_image_path = os.path.join(output_directory, file_name)
        cv2.imwrite(output_image_path, img_with_alpha)

        # 12. Display the output image (optional)
        print(f"Processed image: {file_name}")
